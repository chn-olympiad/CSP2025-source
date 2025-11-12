#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

const int N = 100005;

string s1[N], s2[N];

unsigned long long hs1[N], hs2[N], ht1[N], ht2[N], p[N];

int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    p[0] = 1;
    for (int i = 1; i < N; i++) p[i] = p[i - 1] * 131;
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        cin >> s1[i] >> s2[i];
        for (int j = 0; j < s1[i].size(); j++)
        {
            hs1[i] *= 131;
            hs2[i] *= 131;
            hs1[i] += s1[i][j];
            hs2[i] += s2[i][j];
        }
    }
    while (q--)
    {
        string t1, t2;
        cin >> t1 >> t2;
        if (t1.size() != t2.size())
        {
            printf("0\n");
            continue;
        }
        for (int i = 0; i < t1.size(); i++)
        {
            ht1[i] = ht1[i - 1] * 131 + t1[i];
            ht2[i] = ht2[i - 1] * 131 + t2[i];
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= t1.size() - s1[i].size() + 1; j++)
            {
                int k = j + s1[i].size() - 1;
                if (ht1[k] - ht1[j] * p[s1[i].size()] != hs1[i]) continue;
                unsigned long long tmp = ht1[j - 1] * p[n - i] + hs2[i] * p[n - i - j] + ht1[t1.size()] - ht1[j + i] * p[t1.size() - j - i];
                if (tmp == ht2[t1.size()]) cnt++;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}