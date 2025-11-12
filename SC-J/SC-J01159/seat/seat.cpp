#include<bits/stdc++.h>
#define itn int
#define pii pair<int,int>
#define el cout<<"\n"
#define fi first
#define se second
#define N 110
#define int long long
using namespace std;
itn n, m, ap[N], x, a[N];
signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
		ap[a[i]] = 1;
	}
	for (itn i = 100; i; i--) {
		if (ap[i])x++;
		if (i == a[1])break;
	}
	cout << ((x - 1) / n) + 1 << " ";
	if (((x - 1) % (n << 1) + 1) <= n)cout << ((x - 1) % (n << 1) + 1);
	else cout << (m << 1) - ((x - 1) % (n << 1) + 1) + 1;
	return 0;
}
//很好奇第一轮1分的人怎么进的第二轮