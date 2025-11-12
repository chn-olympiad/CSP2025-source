#include <bits/stdc++.h>
using namespace std;

#define int long long
int n, m, a[1000005], ans, cnt;
bool cmp(int x, int y) { return x > y; }

signed main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n * m; i++) cin >> a[i];
    int temp = a[1];
    sort(a + 1, a + n * m + 1, cmp);
    for(int i = 1; i <= n * m; i++) if(a[i] == temp) {temp = i; break;}
    int t1 = temp / n + 1, t2 = temp % n;
    if(t2 == 0) t1--, t2 = n;
    cout << t1 << ' ';
    if(t1 % 2 == 0)
    {
        t2 = (n + 1) - t2;
    }
    cout << t2;
    return 0;
}
