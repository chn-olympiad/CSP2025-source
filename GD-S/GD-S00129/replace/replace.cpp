#include <bits/stdc++.h>
using namespace std;
int n, q;
int len;
const int N = 2e5 + 5;
struct replace_my_fdjksla
{
    string u, v, uu, vv;
} r[N];
int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        cin >> r[i].u >> r[i].v;
        int j = 0, k = r[i].u.size() - 1;
        while (r[i].u[j] == r[i].v[j] && j < r[i].u.size())
            j++;
        while (r[i].u[k] == r[i].v[k] && k > j)
            k--;
        for (int m = j; m <= k; m++)
        {
            r[i].uu += r[i].u[m];
            r[i].vv += r[i].v[m];
        }
    }
    while (q--)
    {
        string st, ta, stt, taa;
        cin >> st >> ta;
        int len = st.size();
        int j = 0, k = len - 1;
        while (st[j] == ta[j] && j < len)
            j++;
        while (st[k] == ta[k] && k > j)
            k--;
        for (int m = j; m <= k; m++)
        {
            stt += st[m];
            taa += ta[m];
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if ((st.find(r[i].u) <= len) && (st.find(r[i].u) <= len) && (stt == r[i].uu) && (taa == r[i].vv))
                ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}