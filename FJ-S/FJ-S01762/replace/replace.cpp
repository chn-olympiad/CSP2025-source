#include <bits/stdc++.h>
using namespace std;
#define FILE(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout);
#define ll long long
#define pb push_back
const int N = 2e5 + 5, M = 6e6 + 5;
const ll mod = 1000000000039, K = 13131;
int n, q, cnt, a[N], o[M], t[M][26], w[M];
string x, y; map <ll, int> rt;
void ins(int rt, int m)
{
    int u = rt;
    for (int i = 1; i <= m; i++) 
    {
        if (!t[u][o[i]]) t[u][o[i]] = ++cnt;
        u = t[u][o[i]];
    }
    w[u]++;
}
int qry(int rt, int m)
{
    int u = rt, ret = w[u];
    for (int i = 1; i <= m; i++) 
    {
        if (!t[u][o[i]]) break;
        u = t[u][o[i]]; ret += w[u];
    }
    return ret;
}
int main()
{
    FILE("replace");
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int _ = 1; _ <= n; _++)
    {
        cin >> x >> y; int m = x.size(), r = -1; ll h = 0;
        for (int i = m - 1; i >= 0; i--) if (x[i] != y[i]) {r = i; break;} if (r < 0) continue;
        for (int i = r; i >= 0; i--) h = (h * K + (x[i] - 'a') * 26 + (y[i] - 'a') + 1);
        if (!rt.count(h)) rt[h] = ++cnt; 
        for (int i = r + 1; i < m; i++) o[i-r] = x[i] - 'a'; ins(rt[h], m - r - 1);
    }
    while (q--)
    {
        cin >> x >> y; int ans = 0;
        if ((int)x.size() != (int)y.size()) {cout << "0\n"; continue;}
        int m = x.size(), l = -1, r = -1; ll h = 0;
        for (int i = m - 1; i >= 0; i--) if (x[i] != y[i]) {r = i; break;}
        for (int i = 0; i < m; i++) if (x[i] != y[i]) {l = i; break;}
        for (int i = r + 1; i < m; i++) o[i-r] = x[i] - 'a';
        for (int i = r; i >= 0; i--) 
        {
            h = (h * K + (x[i] - 'a') * 26 + (y[i] - 'a') + 1);
            if (i <= l && rt.count(h)) ans += qry(rt[h], m - r - 1);
        }
        cout << ans << "\n";
    }
    return 0;
}