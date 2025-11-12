#include<bits/stdc++.h>
#include<cstdio>
#define ll long long
using namespace std;

const int N = 120;
ll n, m, ming, a[N], ranked[N][N];

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(ll i = 1; i <= n * m; i++) cin >> a[i];
	ming = a[1];
	sort(a + 1, a + n * m + 1, greater<ll>());
	
	// 预处理座位编号 
	ll cnt = 1;
	for(ll y = 1; y <= m; y++)
	{
		if(y % 2 == 1)
		{
			for(ll x = 1; x <= n; x++)
			{
				ranked[x][y] = cnt;
				cnt++;
			}
		}
		else
		{
			for(ll x = n; x >= 1; x--)
			{
				ranked[x][y] = cnt;
				cnt++;
			}
		}
	}
	
	// 查找座位编号
	ll seat_id = 0;
	for(ll i = 1; i <= n * m ; i++)
	{
		if(ming == a[i])
		{
			seat_id = i;
		}
	} 
	 
	// 输出座位编号 
	for(ll i = 1; i <= n; i++)
	{
		for(ll j = 1; j <= m; j++)
		{
			if(ranked[i][j] == seat_id)
			{
				cout << j << " " << i << "\n";
				return 0;
			}
		}
	}
	return 0;	
} 
