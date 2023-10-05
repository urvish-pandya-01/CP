#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define PI 3.1415926535897932384626
#define si(x) scanf("%d", &x)
#define null NULL
#define sz(x) x.size()
#define test(t) \
    int t;      \
    cin >> t;   \
    while (t--) \
    solve()
#define sl(x) scanf("%lld", &x)
#define sss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define br printf("\n")
#define read1(a) cin >> a;
#define read2(a, b) cin >> a >> b;
#define read3(a, b, c) cin >> a >> b >> c;
#define readv(a)      \
    for (auto &i : a) \
        cin >> i;
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define deba(i, a, n) \
    fo(i, n) { cout << a[i] << " "; }
#define pb push_back
#define mpp make_pair
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, x) for (auto it = x.begin(); it != x.end(); it++)
#define trr(it, x) for (auto it = x.rbegin(); it != x.rend(); it +)
#define countofset(n) __builtin_popcount(n);
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef priority_queue<int> pqmax;
typedef priority_queue<int, vector<int>, greater<int>> pqmin;
typedef map<int, int> mii;
const long long int mod = 1e9 + 7;
const int N = 3e5;
const int MAXN = 1000005;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}


mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim)
{
    uniform_int_distribution<int> uid(0, lim - 1);
    return uid(rang);
}

bool sortbysec(const pair<ll, string> &a, const pair<ll, string> &b)
{
    return (a.second < b.second);
}
bool sortinrevf(const pair<ll, string> &a, const pair<ll, string> &b)
{
    return (a.first > b.first);
}

bool powof2(ll n)
{
    return n & (!(n & (n - 1)));
}
void clearlastset(int &a)
{
    // cout << a << endl;
    a = a & (a - 1);
    // cout << a << endl;
}

//Construct Binary Tree from an array
struct node
{
    int data;
    node *left;
    node *right;
};
node *newnode(int data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->left = null;
    temp->right = null;
    return (temp);
}
node *insertLevelOrder(int a[], int n, int i, node *root)
{
    if (i < n)
    {
        node *temp = newnode(a[i]);
        root = temp;
        root->left = insertLevelOrder(a, n, 2 * i + 1, root->left);
        root->right = insertLevelOrder(a, n, 2 * i + 2, root->right);
    }
    return root;
}

// Matrix Implementation
// Matrix Exponentiation

struct Mat {
    int n, m;
    vector<vector<int>> a;
    Mat() { }
    Mat(int _n, int _m) {n = _n; m = _m; a.assign(n, vector<int>(m, 0)); }
    Mat(vector< vector<int> > v) { n = v.size(); m = n ? v[0].size() : 0; a = v; }
    inline void make_unit() {
        assert(n == m);
        for (int i = 0; i < n; i++)  {
            for (int j = 0; j < n; j++) a[i][j] = i == j;
        }
    }
    inline Mat operator + (const Mat &b) {
        assert(n == b.n && m == b.m);
        Mat ans = Mat(n, m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans.a[i][j] = (a[i][j] + b.a[i][j]) % mod;
            }
        }
        return ans;
    }
    inline Mat operator - (const Mat &b) {
        assert(n == b.n && m == b.m);
        Mat ans = Mat(n, m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans.a[i][j] = (a[i][j] - b.a[i][j] + mod) % mod;
            }
        }
        return ans;
    }
    inline Mat operator * (const Mat &b) {
        assert(m == b.n);
        Mat ans = Mat(n, b.m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < b.m; j++) {
                for (int k = 0; k < m; k++) {
                    ans.a[i][j] = (ans.a[i][j] + 1LL * a[i][k] * b.a[k][j] % mod) % mod;
                }
            }
        }
        return ans;
    }
    inline Mat pow(long long k) {
        assert(n == m);
        Mat ans(n, n), t = a; ans.make_unit();
        while (k) {
            if (k & 1) ans = ans * t;
            t = t * t;
            k >>= 1;
        }
        return ans;
    }
    inline Mat& operator += (const Mat& b) { return *this = (*this) + b; }
    inline Mat& operator -= (const Mat& b) { return *this = (*this) - b; }
    inline Mat& operator *= (const Mat& b) { return *this = (*this) * b; }
    inline bool operator == (const Mat& b) { return a == b.a; }
    inline bool operator != (const Mat& b) { return a != b.a; }
};

template <const int32_t MOD>
struct modint {
    int32_t value;
    modint() = default;
    modint(int32_t value_) : value(value_) {}
    inline modint<MOD> operator + (modint<MOD> other) const { int32_t c = this->value + other.value; return modint<MOD>(c >= MOD ? c - MOD : c); }
    inline modint<MOD> operator - (modint<MOD> other) const { int32_t c = this->value - other.value; return modint<MOD>(c <    0 ? c + MOD : c); }
    inline modint<MOD> operator * (modint<MOD> other) const { int32_t c = (int64_t)this->value * other.value % MOD; return modint<MOD>(c < 0 ? c + MOD : c); }
    inline modint<MOD> & operator += (modint<MOD> other) { this->value += other.value; if (this->value >= MOD) this->value -= MOD; return *this; }
    inline modint<MOD> & operator -= (modint<MOD> other) { this->value -= other.value; if (this->value <    0) this->value += MOD; return *this; }
    inline modint<MOD> & operator *= (modint<MOD> other) { this->value = (int64_t)this->value * other.value % MOD; if (this->value < 0) this->value += MOD; return *this; }
    inline modint<MOD> operator - () const { return modint<MOD>(this->value ? MOD - this->value : 0); }
    modint<MOD> pow(uint64_t k) const { modint<MOD> x = *this, y = 1; for (; k; k >>= 1) { if (k & 1) y *= x; x *= x; } return y; }
    modint<MOD> inv() const { return pow(MOD - 2); }  // MOD must be a prime
    inline modint<MOD> operator /  (modint<MOD> other) const { return *this *  other.inv(); }
    inline modint<MOD> operator /= (modint<MOD> other)       { return *this *= other.inv(); }
    inline bool operator == (modint<MOD> other) const { return value == other.value; }
    inline bool operator != (modint<MOD> other) const { return value != other.value; }
    inline bool operator < (modint<MOD> other) const { return value < other.value; }
    inline bool operator > (modint<MOD> other) const { return value > other.value; }
};
template <int32_t MOD> modint<MOD> operator * (int64_t value, modint<MOD> n) { return modint<MOD>(value) * n; }
template <int32_t MOD> modint<MOD> operator * (int32_t value, modint<MOD> n) { return modint<MOD>(value % MOD) * n; }
template <int32_t MOD> istream & operator >> (istream & in, modint<MOD> &n) { return in >> n.value; }
template <int32_t MOD> ostream & operator << (ostream & out, modint<MOD> n) { return out << n.value; }

using mint = modint<mod>;

struct combi {
    int n; vector<mint> facts, finvs, invs;
    combi(int _n): n(_n), facts(_n), finvs(_n), invs(_n) {
        facts[0] = finvs[0] = 1;
        invs[1] = 1;
        for (int i = 2; i < n; i++) invs[i] =  invs[mod % i] * (-mod / i);
        for (int i = 1; i < n; i++) {
            facts[i] = facts[i - 1] * i;
            finvs[i] = finvs[i - 1] * invs[i];
        }
    }
    inline mint fact(int n) { return facts[n]; }
    inline mint finv(int n) { return finvs[n]; }
    inline mint inv(int n) { return invs[n]; }
    inline mint ncr(int n, int k) { return n < k or k < 0 ? 0 : facts[n] * finvs[k] * finvs[n - k]; }
};
combi C(N);
mint lucas(ll n, ll r) {
    if (r > n) return 0;
    if (n < mod) return C.ncr(n, r);
    return lucas(n / mod, r / mod) * lucas(n % mod, r % mod);
}
ll extendedEuclidean(ll a, ll b, ll &x, ll &y)
{
    if (b == 0) {
        y = 0;
        x = 1;
        return a;
    }
    ll x1, y1;
    ll g = extendedEuclidean(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

void modInverse(ll a, ll m)
{
    ll x, y;
    ll g = extendedEuclidean(a, m, x, y);
    if (g != 1) {
        cout << "Does not exist" << endl;
    }
    else
    {
        cout << (x % m + m) % m << endl;
    }
}



// >> means divide
// << means multiply

ll powm(ll a, ll b, ll c)
{
    a = a % c;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = (res * a) % c;
        }

        a = (a * a) % c;

        // cout << res << endl;
        b >>= 1;
    }
    return (res + c) % c;
}
struct segment_tree {
    vector<ll> seg;
    segment_tree(ll n) {
        seg.resize(2 * n);
    }
    void build(vector<ll>& arr)
    {
        ll n = arr.size();
        for (ll i = 0; i < n; ++i) {
            seg[n + i] = arr[i];
        }
        for (ll i = n - 1; i >= 1; --i) {
            seg[i] = __gcd(seg[2 * i], seg[2 * i + 1]);
        }
    }
    ll query(ll l, ll r, ll n)
    {
        l += n;
        r += n;
        ll ans = 0;
        while (l <= r) {
            if (l & 1) {
                ans = __gcd(ans, seg[l]);
                l++;
            }
            if (!(r & 1)) {
                ans = __gcd(ans, seg[r]);
                r--;
            }
            l = l >> 1;
            r = r >> 1;
        }
        return ans;
    }

};

vector<ll> primes;
vector<bool> is_prime(N + 1, true);
void sieve_of_eratosthenes() {
    is_prime[0] = is_prime[1] = false;
    // cout << "N is " << N << endl;
    // cout << is_prime.size() << endl;
    for (int i = 2; i * i <= N; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= N; j += i)
                is_prime[j] = false;
        }
    }
    for (int i = 2; i <= N; i++) {
        if (is_prime[i]) {
            primes.pb(i);
        }
    }
}




/* ========== YOUR CODE HERE ========= */

//  To use  Ncr combinatrices function use the struct combi C
//  ncr fucntion is defined and
//  the limit is N = 3e5 + 9.

void solve()
{
    ll i, j, k, n, m, ans = 0, f = 0;
    string s;
    cin >> n >> m;
    ll a[n][m];
    // k = primes.size();
    // cout << primes[k - 1] << endl;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cin >> a[i][j];
            a[i][j] = *(lower_bound(primes.begin(), primes.end(), a[i][j])) - a[i][j];
        }
    }
    ans = 1e10;
    // for (i = 0; i < n; i++) {
    //     for (j = 0; j < m; j++) {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    for (i = 0; i < n; i++) {
        f = 0;
        for (j = 0; j < m; j++) {
            f += a[i][j];
        }
        ans = min(ans, f);
    }
    for (j = 0; j < m; j++) {
        f = 0;
        for (i = 0; i < n; i++) {
            f += a[i][j];
        }
        ans = min(ans, f);
    }
    cout << ans << endl;

}
/* ========== YOUR CODE HERE ========= */

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif

#ifndef ONLINE_JUDGE
    freopen("F:/Temp/Programs/input.txt", "r", stdin);
    freopen("F:/Temp/Programs/output.txt", "w", stdout);
#endif
    // test(t);
    sieve_of_eratosthenes();
    solve();

    return 0;
}