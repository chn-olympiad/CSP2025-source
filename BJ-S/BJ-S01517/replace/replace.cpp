#include <iostream>
#define ull unsigned long long
using namespace std;

const ull p = 131;

int n, t;
int ln[200010];
ull hsa[200010], hsb[200010];
ull hs[200010];
ull pw[200010];

ull get_hs(string s)
{
    ull h = 0;
    for (int i = 0; i < s.size(); ++i)
        h = h * p + s[i];
    return h;
}

void hss(string s)
{
    for (int i = 0; i < s.size(); ++i)
        hs[i] = (i == 0 ? 0 : hs[i - 1]) * p + s[i];
}

ull query(int l, int r)
{
    if (l > r)
        return 0;
    return hs[r] - (l == 0 ? 0 : hs[l - 1]) * pw[r - l + 1];
}

void init()
{
    pw[0] = 1;
    for (int i = 1; i <= 200000; ++i)
        pw[i] = pw[i - 1] * p;
}

int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> t;
    for (int i = 1; i <= n; ++i)
    {
        string s1, s2;
        cin >> s1 >>s2;
        ln[i] = s1.size();
        hsa[i] = get_hs(s1);
        hsb[i] = get_hs(s2);
    }
    init();
    while (t--)
    {
        string s1, s2;
        cin >> s1 >>s2;
        hss(s1);
        ull tg = get_hs(s2);
        int cnt = 0;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j + ln[i] - 1 < s1.size(); ++j)
                if (query(j, j + ln[i] - 1) == hsa[i])
                {
                    ull nw = query(0, j - 1) * pw[s1.size() - j]     +     hsb[i] * pw[s1.size() - (j + ln[i] - 1) - 1]    +    query(j + ln[i], s1.size() - 1);
                    //cout << i << ' ' << j << ' ' << nw << ' ' << tg << '\n';
                    if (nw == tg)
                        ++cnt;
                }
        }
        cout << cnt << '\n';
    }
    return 0;
}
