#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read()
{
    register int x = 0, f = 1;
    register char c = getchar();
    while(c < '0' || c > '9'){if(c == '-')f = -1;c = getchar();}
    while(c <= '9' && c >= '0'){x = x * 10 + c - '0', c = getchar();}
    return x * f;
}

inline void write(__int128 x)
{
    if(x < 0)putchar('-'), x = -x;
    if(x <= 10)return (void)(putchar(x + '0'));
    write(x / 10), putchar(x % 10 + '0');
    return;
}

const __int128 mod = 1234567891011121343ll;

const int base = 37;

string s1[200010], s2[200010];

inline __int128 ksm(int x, int y)
{
    __int128 ans = 1, res = x;
    while(y)
    {
        if(y & 1)ans = (ans * res) % mod;
        res = (res * res) % mod;
        y >>= 1;
    }
    return ans;
}

__int128 inv[5000010];

int l[200010], r[200010], len[200010];

vector <__int128> hsh1[200010], hsh2[200010];

__int128 v1[5000010], v2[5000010];

// __int128 hsh1(int x, int l, int r)
// {
//     return ((((hsh1[x][r] - hsh1[x][l - 1] % mod) + mod) % mod) * inv[l - 1]) % mod;
// }

// __int128 hsh2(int x, int l, int r)
// {
//     return ((((hsh2[x][r] - hsh2[x][l - 1] % mod) + mod) % mod) * inv[l - 1]) % mod;
// }

bool ok[200010];

signed main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    inv[0] = 1, inv[1] = base;
    for(int i = 2;i <= 500000;i++)inv[i] = (inv[i - 1] * base) % mod;
    for(int i = 1;i <= n;i++)
    {
        cin >> s1[i] >> s2[i];
        len[i] = s1[i].length();
        s1[i] = " " + s1[i];
        s2[i] = " " + s2[i];
        for(int j = 1;j <= len[i];j++)
        {
            if(s1[i][j] != s2[i][j])
            {
                l[i] = j;
                break;
            }
        }
        for(int j = len[i];j >= 1;j--)
        {
            if(s1[i][j] != s2[i][j])
            {
                r[i] = len[i] - j + 1;
                break;
            }
        }
        // cout << l[i] << ' ' << r[i] << "\n";
        hsh1[i].resize(len[i] + 2);
        hsh2[i].resize(len[i] + 2);
        for(int j = 1;j <= len[i];j++)
        {
            hsh1[i][j] = (hsh1[i][j - 1] * base + s1[i][j] - 'a' + 1) % mod;//, write(hsh1[i][j]), putchar(' ');
            hsh2[i][j] = (hsh2[i][j - 1] * base + s2[i][j] - 'a' + 1) % mod;//, write(hsh2[i][j]), putchar(' ');
        }
        // cout << "\n";
    }
    if((n <= 1000 && q <= 2000) || q == 1)
    {
        while(q--)
        {
            for(int i = 1;i <= n;i++)ok[i] = 1;
            string t1, t2;
            cin >> t1 >> t2;
            int L, R;
            int m = t1.length();
            if(m != t2.length())
            {
                cout << "0\n";
                continue;
            }
            t1 = " " + t1;
            t2 = " " + t2;
            for(int j = 1;j <= m;j++)
            {
                if(t1[j] != t2[j])
                {
                    L = j;
                    break;
                }
            }
            for(int j = m;j >= 1;j--)
            {
                if(t1[j] != t2[j])
                {
                    R = m - j + 1;
                    break;
                }
            }
            // cout << L << ' ' << R << '\n';
            for(int i = 1;i <= m;i++)v1[i]= (v1[i - 1] * base + t1[i] - 'a' + 1) % mod;
            for(int i = 1;i <= m;i++)v2[i]= (v2[i - 1] * base + t2[i] - 'a' + 1) % mod;
            // cout << "\n";
            int ans = 0;
            for(int i = 1;i <= n;i++)
            {
                if(l[i] > L || (len[i] - r[i] + 1 > m - R + 1))continue;
                // cout << "ok " << ' ' << i << ' ' << m - R + 1 + r[i] - 1 << ' ' << L - l[i] << ' ';
                // write(inv[L - l[i]]);
                // putchar(' ');
                // write(((v1[(m - R + 1) + r[i] - 1] - v1[L - l[i]] * inv[(m - R + 1) + r[i] - 1 - (L - l[i])] % mod + mod) % mod) % mod);
                // putchar(' ');
                // write(((v2[(m - R + 1) + r[i] - 1] - v2[L - l[i]] * inv[(m - R + 1) + r[i] - 1 - (L - l[i])] % mod + mod) % mod) % mod);
                // putchar(' ');
                // write(hsh1[i][len[i]]);
                // putchar(' ');
                // write(hsh2[i][len[i]]);
                // putchar('\n');
                if(((v1[(m - R + 1) + r[i] - 1] - v1[L - l[i]] * inv[(m - R + 1) + r[i] - 1 - (L - l[i])] % mod + mod) % mod) % mod == hsh1[i][len[i]])
                {
                    if(((v2[(m - R + 1) + r[i] - 1] - v2[L - l[i]] * inv[(m - R + 1) + r[i] - 1 - (L - l[i])] % mod + mod) % mod) % mod == hsh2[i][len[i]])
                    {
                        // cout << i << '\n';
                        ans++;
                    }
                }
            }
            cout << ans << "\n";
        }
        return 0;
    }
    return 0;
}