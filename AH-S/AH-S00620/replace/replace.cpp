#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

using ull = unsigned long long;
constexpr int maxn = 200000, maxs = 5000000, p = 131;
ull val[maxn + 5][2], hc1[maxs + 5], hc2[maxs + 5], pw[maxs + 5];
char s1[maxs + 5], s2[maxs + 5];
int len[maxn + 5][2], pos[maxn + 5][2];

inline ull get_code1(int l, int r)
{ return hc1[r] - hc1[l - 1] * pw[r - l + 1]; }

inline ull get_code2(int l, int r)
{ return hc2[r] - hc2[l - 1] * pw[r - l + 1]; }

namespace subtask1
{
    void solve(int n, int q)
    {
        while (q--)
        {
            scanf("%s %s", s1 + 1, s2 + 1);
            int len1 = strlen(s1 + 1), len2 = strlen(s2 + 1);
            if (len1 != len2)
            { puts("0"); continue; }

            for (int i = 1; i <= len1; i++)
                hc1[i] = hc1[i - 1] * p + s1[i];
            for (int i = 1; i <= len2; i++)
                hc2[i] = hc2[i - 1] * p + s2[i];
            
            int ans = 0;
            for (int i = 1; i <= len1; i++)
            {
                if (get_code1(1, i - 1) != get_code2(1, i - 1))
                    break;
                for (int j = 1; j <= n; j++)
                    if (i + len[j][0] - 1 <= len1)
                        if (val[j][0] == get_code1(i, i + len[j][0] - 1) && val[j][1] == get_code2(i, i + len[j][1] - 1) 
                                && get_code1(i + len[j][0], len1) == get_code2(i + len[j][1], len1))
                            ans++;
            }
            printf("%d\n", ans);
        }
    }
}

namespace subtask2
{
    void solve(int n)
    {
        scanf("%s %s", s1 + 1, s2 + 1);
        int len1 = strlen(s1 + 1), len2 = strlen(s2 + 1);
        if (len1 != len2)
        { puts("0"); return; }

        int first = 0, last = 0;
        for (int i = 1; i <= len1; i++)
            if (s1[i] != s2[i])
            { first = i; break; }
        for (int i = len1; i >= 1; i--)
            if (s1[i] != s2[i])
            { last = i; break; }

        for (int i = 1; i <= len1; i++)
            hc1[i] = hc1[i - 1] * p + s1[i];
        for (int i = 1; i <= len2; i++)
            hc2[i] = hc2[i - 1] * p + s2[i];

        int ans = 0;
        for (int i = 1; i <= n; i++)
            if (pos[i][0] && last - first + 1 == pos[i][1] - pos[i][0] + 1)
                if (pos[i][0] - 1 <= first - 1 && len[i][0] - pos[i][1] <= len1 - last)
                    if (val[i][0] == get_code1(first - pos[i][0] + 1, last + len[i][0] - pos[i][1])
                            && val[i][1] == get_code2(first - pos[i][0] + 1, last + len[i][0] - pos[i][1]))
                        ans++;
        printf("%d\n", ans);
    }
}

int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        scanf("%s %s", s1 + 1, s2 + 1);
        int cl1 = strlen(s1 + 1), cl2 = strlen(s2 + 1);
        ull cur = 0;
        for (int k = 1; k <= cl1; k++)
            cur = cur * p + s1[k];
        val[i][0] = cur;
        cur = 0;
        for (int k = 1; k <= cl2; k++)
            cur = cur * p + s2[k];
        val[i][1] = cur;
        len[i][0] = cl1;
        len[i][1] = cl2;

        for (int j = 1; j <= cl1; j++)
            if (s1[j] != s2[j])
            { pos[i][0] = j; break; }
        for (int j = cl1; j >= 1; j--)
            if (s1[j] != s2[j])
            { pos[i][1] = j; break; }
    }

    pw[0] = 1;
    for (int i = 1; i <= maxs; i++)
        pw[i] = pw[i - 1] * p;

    if (n <= 2000 && q <= 2000)
        subtask1::solve(n, q);
    else if (1 == q)
        subtask2::solve(n);
    else
        subtask3::solve(n, q);

    return 0;
}