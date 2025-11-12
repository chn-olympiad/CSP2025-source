#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define int ll

const int N = 2e5 + 10;
const int M = 1e6 + 10;
const ull B = 233;
ull pwb[N];

int n, q, len[N], sp[N], tp[N], ls[N], rs[N], lt[N], rt[N];
string ss[N], tt[N];
ull a[N][2], h[M];
vector<int> vec[M * 2];

ull hah(const string &s)
{
    ull res = 0;
    for (char ch : s)
    {
        res = res * B + ch;
    }
    return res;
}
constexpr ull get(int l, int r)
{
    if (l > r)
    {
        return 0;
    }
    return h[r] - h[l - 1] * pwb[r - l + 1];
}

signed main()
{
    if (1)
    {
        freopen("replace.in", "r", stdin);
        freopen("replace.out", "w", stdout);
    }
    cin.tie(0)->sync_with_stdio(0), cout << fixed << setprecision(10);
    pwb[0] = 1;
    for (int i = 1; i < N; ++i)
    {
        pwb[i] = pwb[i - 1] * B;
    }
    cin >> n >> q;
    int l1 = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> ss[i] >> tt[i];
        a[i][0] = hah(ss[i]);
        a[i][1] = hah(tt[i]);
        len[i] = ss[i].size();
        l1 += len[i] + len[i];
    }
    string s, t;
    if (l1 > 10000)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j < len[i]; ++j)
            {
                if (ss[i][j] == 'b')
                {
                    sp[i] = j + 1;
                    break;
                }
            }
            for (int j = 0; j < len[i]; ++j)
            {
                if (tt[i][j] == 'b')
                {
                    tp[i] = j + 1;
                    break;
                }
            }
            ls[i] = sp[i] - 1, rs[i] = len[i] - sp[i];
            lt[i] = tp[i] - 1, rt[i] = len[i] - tp[i];
            vec[tp[i] - sp[i] + M].push_back(i);
        }
        while (q--)
        {
            cin >> s >> t;
            int siz = s.size(), qsp = 0, qtp = 0;
            for (int i = 0; i < siz; ++i)
            {
                if (s[i] == 'b')
                {
                    qsp = i + 1;
                    break;
                }
            }
            for (int i = 0; i < siz; ++i)
            {
                if (t[i] == 'b')
                {
                    qtp = i + 1;
                    break;
                }
            }
            int qls = qsp - 1, qrs = siz - qsp;
            int qlt = qtp - 1, qrt = siz - qtp;
            int res = 0;
            for (int i : vec[qtp - qsp + M])
            {
                res += ls[i] <= qls && rs[i] <= qrs && lt[i] <= qlt && rt[i] <= qrt;
            }
            cout << res << '\n';
        }
        return 0;
    }
    while (q--)
    {
        cin >> s >> t;
        int siz = s.size();
        ull ht = hah(t);
        s = "$" + s;
        for (int i = 1; i <= siz; ++i)
        {
            h[i] = h[i - 1] * B + s[i];
        }
        int res = 0;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = len[i]; j <= siz; ++j)
            {
                if (get(j - len[i] + 1, j) == a[i][0])
                {
                    ull ns = get(1, j - len[i]) * pwb[siz - j + len[i]] + a[i][1] * pwb[siz - j] + get(j + 1, siz);
                    res += ns == ht;
                }
            }
        }
        cout << res << '\n';
    }
}