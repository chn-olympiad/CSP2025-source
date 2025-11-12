#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <tuple>

using namespace std;

const int N = 2e5 + 10, mod = 1e9 + 7; // don't hack my hash, or I will write 2 mod + ull hash !!!!!!

#define int long long

using pii = pair <int, int>;
using ull = unsigned long long;
const ull base = 131;

#define fi first
#define se second

string s[N][2], t[N][2];
struct Node
{
    ull pre, mid1, mid2;
    string nxt;
}hs[N];
map <tuple <ull, ull, ull, ull>, int> cnt, ct;
map <tuple <ull, ull, ull, ull>, bool> vis;
ull has[N];

signed main()
{
    freopen("data.in", "r", stdin); freopen("data.out", "w", stdout);
    freopen("replace.in", "r", stdin); freopen("replace.out", "w", stdout);
    ios :: sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> s[i][0] >> s[i][1];
    for (int i = 1; i <= q; i++)
        cin >> t[i][0] >> t[i][1];
    int tot = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i][0] == s[i][1]) continue;
        int l = 0, r = 0;
        ull pre_hash = 0, mid_hash1 = 0, mid_hash2 = 0;
        string nxt_string;
        for (l = 1; l <= (int)s[i][0].size(); l++) if (s[i][0][l - 1] != s[i][1][l - 1]) break;
        for (r = (int)s[i][0].size(); r >= 1; r--) if (s[i][0][r - 1] != s[i][1][r - 1]) break;
        for (int j = 1; j < l; j++) pre_hash = pre_hash * base + s[i][0][j - 1];
        for (int j = l; j <= r; j++) mid_hash1 = mid_hash1 * base + s[i][0][j - 1], mid_hash2 = mid_hash2 * base + s[i][1][j - 1];
        for (int j = r + 1; j <= (int)s[i][0].size(); j++) nxt_string.push_back(s[i][0][j - 1]);
        hs[++tot] = {pre_hash, mid_hash1, mid_hash2, nxt_string};
    }
    sort(hs + 1, hs + 1 + tot, [](Node x, Node y) {return x.nxt.size() < y.nxt.size();});
    for (int i = 1; i <= tot; i++)
    {
        ull nowhash = 0;
        int precnt = 0;
        for (int j = 0; j <= (int)hs[i].nxt.size(); j++)
        {
            if (j) nowhash = nowhash * base + hs[i].nxt[j - 1];
            auto tmp = make_tuple(hs[i].pre, hs[i].mid1, hs[i].mid2, nowhash);
            vis[tmp] = 1;
            cnt[tmp] = precnt + ct[tmp];
            precnt = cnt[tmp];
            // if (j == (int)hs[i].nxt.size() && nowhash == 2685535975923119886) cerr << 123;
            if (j == (int)hs[i].nxt.size()) ct[tmp]++, cnt[tmp]++;
        }
    }
    for (int i = 1; i <= q; i++)
    {
        int l = 0, r = 0;
        ull pre_hash = 0, mid_hash1 = 0, mid_hash2 = 0;
        for (l = 1; l <= (int)t[i][0].size(); l++) if (t[i][0][l - 1] != t[i][1][l - 1]) break;
        for (r = (int)t[i][0].size(); r >= 1; r--) if (t[i][0][r - 1] != t[i][1][r - 1]) break;
        // if (i == 101) cerr << t[i][0] << ' ' << t[i][1] << ' ' << l <<  ' ' << r << '\n';
        // if (i != 101) continue;
        // for (int j = 1; j < l; j++) pre_hash = pre_hash * base + t[i][0][l - 1];
        for (int j = l; j <= r; j++) mid_hash1 = mid_hash1 * base + t[i][0][j - 1], mid_hash2 = mid_hash2 * base + t[i][1][j - 1];
        for (int j = r + 1; j <= (int)t[i][0].size(); j++)
        {
            has[j - r] = has[j - r - 1] * base + t[i][0][j - 1];
        }
        ull _base = 1;
        int ans = 0;
        for (int j = l; j >= 1; j--)
        {
            if (j != l)
            {
                pre_hash = pre_hash + _base * t[i][0][j - 1];
                _base = _base * base;
            }
            int L = r, R = t[i][0].size(), pos = 0;
            // for (int k = L; k <= R; k++)
            // {
            //     auto tmp = make_tuple(pre_hash, mid_hash1, mid_hash2, has[k - r]);
            //     if (vis[tmp]) cerr << cnt[tmp] << ' ';
            //     // pos = max(pos, cnt[tmp]);
            // }
            // cerr << '\n';
            while (L <= R)
            {
                int mid = (L + R) >> 1;
                auto tmp = make_tuple(pre_hash, mid_hash1, mid_hash2, has[mid - r]);
                if (vis[tmp]) pos = cnt[tmp], L = mid + 1;
                else R = mid - 1;
            }
            ans += pos;
        }
        cout << ans << '\n';
    }

    return 0;
}