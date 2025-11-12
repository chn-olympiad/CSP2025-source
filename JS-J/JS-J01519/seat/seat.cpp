#include <bits/stdc++.h>
using namespace std;
int n, m, k, cnt = 1;
int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 2, x; i <= n * m; i++)
    {
        cin >> x;
        if(x > k) cnt++;
    }
    int c = cnt / n, r;
    if(cnt % n > 0) c++;
    cnt %= n;
    r = (cnt + n - 1) % n + 1;
    if(c & 1) r;
    else r = m - r + 1;
    cout << c << ' ' << r;
	return 0;
}
