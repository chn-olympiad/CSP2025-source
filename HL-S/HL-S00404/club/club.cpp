#include <bits/stdc++.h>
using namespace std;
const int N = 400010;
struct P
{
	int a[4];
}p[N];
int x[N];
void solve() 
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++ )
	{
		cin >> p[i].a[1] >> p[i].a[2] >> p[i].a[3];
	}
	int cnt[4] = {0, 0, 0, 0}, ans = 0;
	for (int i = 1; i <= n; i ++ )
	{
		if (p[i].a[1] >=p[i]. a[2] && p[i].a[1] >=p[i]. a[3])
		{
			cnt[1] ++ ;
			x[i] = 1;
			ans += p[i].a[1];
		}
		else if (p[i].a[2] >= p[i].a[1] && p[i].a[2] >= p[i].a[3])
		{
			x[i] = 2;
			cnt[2] ++ ;
			ans += p[i].a[2];
		}
		else 
		{
			x[i] = 3;
			cnt[3] ++ ;
			ans += p[i].a[3];
		}
	}
	int ma = max(max(cnt[1], cnt[2]), cnt[3]);
	if (ma <= n / 2)
	{
		cout << ans << '\n';
		return ;
	}
	if (cnt[1] == ma)
	{
		priority_queue<int, vector<int>, greater<int> > q;
		for (int i = 1; i <= n; i ++ )
		{
			if (x[i] == 1)q.push(min(p[i].a[1] - p[i].a[2], p[i].a[1] - p[i].a[3]));
		}
		ma -= n / 2;
		while (ma > 0)
		{
			ans -= q.top();
			
			q.pop();
			ma -- ;
		}
	}
	else if (cnt[2] == ma)
	{
		priority_queue<int, vector<int>,greater<int> > q;
		for (int i = 1; i <= n; i ++ )
		{
			if (x[i] == 2)q.push(min(p[i].a[2] - p[i].a[1], p[i].a[2] - p[i].a[3]));
		}
		ma -= n / 2;
		while (ma > 0)
		{
			ans -= q.top();
			q.pop();
			ma -- ;
		}
	}
	else 
	{
		priority_queue<int, vector<int>,greater<int> > q;
		for (int i = 1; i <= n; i ++ )
		{
			if (x[i] == 3)q.push(min(p[i].a[3] - p[i].a[1], p[i].a[3] - p[i].a[2]));
		}
		ma -= n / 2;
		while (ma > 0)
		{
			ans -= q.top();
			q.pop();
			ma -- ;
		}
	}
	cout << ans << '\n';
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T -- ) 
	{
		solve();
	}
	return 0;
}