#include <bits/stdc++.h>

typedef long long i64;

constexpr i64 MAXN = 2e5 + 10;
constexpr i64 MAXL = 2e3 + 10;

i64 n, q;
std::string s1[MAXN], s2[MAXN];

i64 pf[MAXL];

void solve()
{
    for (; q--; )
    {
        i64 tot = 0;
        std::string t1, t2;
        std::cin >> t1 >> t2;
        i64 len = t1.length();
        for (i64 j = 1; j <= len; ++j)
        {
            pf[j] = pf[j - 1] + (t1[j - 1] == t2[j - 1]);
        }
        for (i64 i = 1; i <= n; ++i)
        {
            for (i64 p = t1.find(s1[i]); p != -1; p = t1.find(s1[i], p + 1))
            {
                i64 s = pf[p] + pf[t1.length()] - pf[p + s1[i].length()];
                for (i64 j = 0; j < s1[i].length(); ++j)
                {
                    s = s + (s2[i][j] == t2[p + j]);
                }
                if(s == t1.length())
                {
                    //printf("OK i=%lld, p=%lld\n", i, p);
                    ++tot;
                }
                else
                {
                    //printf("FAIL i=%lld, p=%lld, s=%lld, len=%lld\n", i, p, s, len);
                }
            }
        }
        std::cout << tot << '\n';
    }
}

struct node
{
    i64 l, r, x;
} S[MAXN];

bool cmp(const node &lhs, const node &rhs)
{
    if (lhs.x == rhs.x)
    {
        if (lhs.l == rhs.l)
        {
            return lhs.r < rhs.r;
        }
        return lhs.l < rhs.l;
    }
    return rhs.x < rhs.x;
}

i64 findx(i64 l, i64 r, i64 x)
{
    while (l < r)
    {
        i64 mid = (l + r) >> 1;
        if (S[mid].x < x)
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }
    return l;
}
i64 findl(i64 l, i64 r, i64 x)
{
    while (l < r)
    {
        i64 mid = (l + r) >> 1;
        if (S[mid].l < x)
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }
    return l;
}
i64 findr(i64 l, i64 r, i64 x)
{
    while (l < r)
    {
        i64 mid = (l + r) >> 1;
        if (S[mid].r < x)
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }
    return l;
}

void subtaskB()
{
    for (i64 i = 1; i <= n; ++i)
    {
        i64 len = s1[i].length(), p1 = 0, p2 = 0;
        for (i64 j = 0; j < len; ++j) if (s1[i][j] == 'b') p1 = j;
        for (i64 j = 0; j < len; ++j) if (s2[i][j] == 'b') p2 = j;
        i64 l = std::min(p1, p2), r = len - std::max(p1, p2) - 1;
        S[i] = {l, r, p2 - p1};
    }
    std::sort(S + 1, S + 1 + n, cmp);
    for (; q--; )
    {
        std::string t1, t2;
        std::cin >> t1 >> t2;
        i64 len = t1.length(), p1 = 0, p2 = 0, tot = 0;
        for (i64 j = 0; j < len; ++j) if (t1[j] == 'b') p1 = j;
        for (i64 j = 0; j < len; ++j) if (t2[j] == 'b') p2 = j;
        i64 x = p2 - p1;
        //i64 L = findx(1, n, x), R = findx(1, n, x + 1) - 1;
        //std::cout << L << ' ' << R << '\n';
        for (i64 i = 1; i <= n; ++i)
        {
            if (S[i].x == x && S[i].l <= std::min(p1, p2) && S[i].r <= len - std::max(p1, p2) - 1)
            {
                ++tot;
            }
        }
        std::cout << tot << '\n';
    }
}
bool isSubB()
{
    return n > 100 && q > 100;
}

signed main()
{
    freopen("replace.out", "w", stdout);
    freopen("replace.in", "r", stdin);
    std::cin >> n >> q;
    for (i64 i = 1; i <= n; ++i) std::cin >> s1[i] >> s2[i];
    if (isSubB()) subtaskB();
    else solve();
    return 0;
}
