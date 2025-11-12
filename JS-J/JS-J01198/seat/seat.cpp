#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int a[n * m + 1];
    for(int i = 0; i < n * m; i++) cin >> a[i];
    int x = a[0];
    sort(a, a + n * m);
    int cnt = 0;
    for(int i = 0; i < n * m; i++) if(x == a[i]) cnt = n * m - i;
    int j;
    if(cnt % n == 0)
    {
        j = cnt / n;
        if(j % 2 == 0) cout << j << " " << 1;
        else cout << j << " " << n;
        return 0;
    }
    else j = cnt / n + 1;
    int y = j * n - cnt;
    if(j % 2 != 0) cout << j << " " << n - y;
    else cout << j << " " << n - y + 1;
}
