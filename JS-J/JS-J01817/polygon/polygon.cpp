#include <bits/stdc++.h>
using namespace std;
int a[5005], ans, _;
#define lp(x, y) for(int x = y; x <= _; x++)
#define lp2(x, y, z, t) lp(x, 1)lp(y, x + 1)lp(z, y + 1)lp(t, z + 1)
#define lp3(x, y, z, t, g, h) lp2(x, y, z, t)lp(g, t + 1)lp(h, g + 1)
int mx(int a, int b, int c) {return max(max(a, b), c);} 
int mxx(int a, int b, int c, int d) {return max(mx(a, b, c), d);} 
int mxxx(int a, int b, int c, int d, int e) {return max(mxx(a, b, c, d), e);} 
int mxa(int a, int b, int c, int d, int e, int f) {return max(mxxx(a, b, c, d, e), f);} 
int mxt(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j) {return max(mxx(a, b, c, d), mxa(e, f, g, h, i, j));} 
signed main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> _;
    for (int i = 1; i <= _; i++)
    {
        cin >> a[i];
    } 
    if (_ == 3)
    {
        if (a[1] + a[2] + a[3] > 2 * mx(a[1], a[2], a[3])) cout << 1;
        else cout << 0;
        cout << "\n";
        return 0;
    } 
    if (_ >= 3)
    {
        for (int i = 1; i <= _; i++) for (int j = i + 1; j <= _; j++) for (int k = j + 1; k <= _; k++) if (a[i] + a[j] + a[k] > 2 * mx(a[i], a[j], a[k])) ans++;
    } 
    if (_ >= 4)
    {
        for (int i = 1; i <= _; i++) for (int j = i + 1; j <= _; j++) for (int k = j + 1; k <= _; k++) for (int l = k + 1; l <= _; l++) if (a[i] + a[j] + a[k] + a[l] > 2 * mxx(a[i], a[j], a[k], a[l])) ans++;
    }
    if (_ >= 5)
    {
        lp(i, 1) lp(j, i + 1) lp(k, j + 1) lp(l, k + 1) lp(m, l + 1) if (a[i] + a[j] + a[k] + a[l] + a[m] > 2 * mxxx(a[i], a[j], a[k], a[l], a[m])) ans++;
    }
    if (_ >= 6)
    {
        lp(i, 1) lp(j, i + 1) lp(k, j + 1) lp(l, k + 1) lp(m, l + 1) lp(n, m + 1) if (a[i] + a[j] + a[k] + a[l] + a[m] + a[n] > 2 * mxa(a[i], a[j], a[k], a[l], a[m], a[n])) ans++;
    } 
    if (_ >= 7)
    {
        lp(i, 1) lp(j, i + 1) lp(k, j + 1) lp(l, k + 1) lp(m, l + 1) lp(n, m + 1) lp(o, m + 1) if (a[i] + a[j] + a[k] + a[l] + a[m] + a[n] + a[o] > 2 * max(mxa(a[i], a[j], a[k], a[l], a[m], a[n]), a[o])) ans++;
    } 
    if (_ >= 8)
    {
        lp2(i, j, k, l) lp(m, l + 1) lp(n, m + 1) lp(o, n + 1) lp(p, o + 1) if (a[i] + a[j] + a[k] + a[l] + a[m] + a[n] + a[o] + a[p] > 2 * mx(a[i], a[j], mxa(a[k], a[l], a[m], a[n], a[o], a[p]))) ans++;
    } 
    if (_ >= 9)
    {
        lp3(i, j, k, l, m, n) lp(o, n + 1) lp(p, o + 1) lp(q, p + 1) if (a[i] + a[j] + a[k] + a[l] + a[m] + a[n] + a[o] + a[p] + a[q] > 2 * mxx(a[i], a[j], a[k], mxa(a[l], a[m], a[n], a[o], a[p], a[q]))) ans++;
    } 
    if (_ >= 10)
    {
        lp3(i, j, k, l, m, n) lp(o, n + 1) lp(p, o + 1) lp(q, p + 1) lp(r, q + 1) if (a[i] + a[j] + a[k] + a[l] + a[m] + a[n] + a[o] + a[p] + a[q] + a[r] > 2 * mxt(a[i], a[j], a[k], a[l], a[m], a[n], a[o], a[p], a[q], a[r])) ans++;
    } 
    cout << ans << "\n";
    return 0;
} 