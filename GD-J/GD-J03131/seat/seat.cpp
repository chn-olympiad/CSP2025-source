#include <bits/stdc++.h>
#define int long long
#define gc getchar()
using namespace std;

int rd()
{
    int x = 0, f = 1;
    char c = gc;
    for(; !isdigit(c); c = gc) if(c == '-') f = -1;
    for(; isdigit(c); c = gc) x = x * 10 + (c ^ 48);
    return x * f;
}

int n, m, x, y;
int a[100000], rk;

signed main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    n = rd(), m = rd();
    for(int i = 1; i <= n * m; i++) a[i] = -rd();
    rk = a[1];
    sort(a + 1, a + n * m + 1);
    for(int i = 1; i <= n * m; i++) if(a[i] == rk) {rk = i;break;}
    x = (rk + n - 1) / n, y = (rk - 1) % n + 1;
    cout << x << " " << ((x & 1) ? y : (n - y + 1));
    return 0;
}
