#include <bits/stdc++.h>
#define int long long

using namespace std;

int T;
int n;
int a[3][100010];
int cha[100010];
int idx[3], b[3][100010];
int ans;

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while(T --)
	{
		cin >> n;
		ans = 0;
		int cnt0 = 0, cnt1 = 0, cnt2 = 0;
		idx[0] = idx[1] = idx[2] = 0;
		for(int i = 1;i <= n;i ++)
		{
			cin >> a[0][i] >> a[1][i] >> a[2][i];
			if(a[0][i] >= a[1][i] && a[0][i] >= a[2][i]) ans += a[0][i], cnt0 ++, b[0][++ idx[0]] = min(a[0][i] - a[1][i], a[0][i] - a[2][i]);
			else if(a[1][i] >= a[0][i] && a[1][i] >= a[2][i]) ans += a[1][i], cnt1 ++, b[1][++ idx[1]] = min(a[1][i] - a[0][i], a[1][i] - a[2][i]);
			else ans += a[2][i], cnt2 ++, b[2][++ idx[2]] = min(a[2][i] - a[0][i], a[2][i] - a[1][i]);
		}
		if(cnt0 * 2 > n)
		{
			sort(b[0] + 1, b[0] + idx[0] + 1);
			for(int i = cnt0, j = 1;i * 2 > n;i --, j ++) ans -= b[0][j];
		}
		else if(cnt1 * 2 > n)
		{
			sort(b[1] + 1, b[1] + idx[1] + 1);
			for(int i = cnt1, j = 1;i * 2 > n;i --, j ++) ans -= b[1][j];
		}
		else if(cnt2 * 2 > n)
		{
			sort(b[2] + 1, b[2] + idx[2] + 1);
			for(int i = cnt2, j = 1;i * 2 > n;i --, j ++) ans -= b[2][j];
		}
		cout << ans << "\n";
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
