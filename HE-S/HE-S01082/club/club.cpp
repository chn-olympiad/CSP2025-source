#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 1e5 + 66;
ll a[N][5], n, t, ans;
priority_queue<pair<ll, pair<ll, ll> > > q[5];
int maxx(int x)
{
	int ma = 1;
	for(int i = 1;i <= 3;i ++) if(a[x][ma] < a[x][i]) ma = i;
	return ma;
}
int nxtma(int x, int ma)
{
	int nx = ma == 1 ? 2 : 1;
	for(int i = 1;i <= 3;i ++) if(a[x][nx] < a[x][i] && i != ma) nx = i;
	return nx;
}
ll las(int ma, int ma2){for(int j = 1;j <= 3;j ++) if(j != ma && j != ma2) return j;}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0), cout.tie(0);
	freopen("club.in", "r", stdin);freopen("club.out", "w", stdout);
	cin >> t;
	while(t --)
	{
		ans = 0;
		cin >> n;
		for(int i = 1;i <= n;i ++) cin >> a[i][1] >> a[i][2] >> a[i][3];
		for(int i = 1;i <= n;i ++)
		{
			int ma = maxx(i);int ma2 = nxtma(i, ma);int ma3 = las(ma, ma2);
			if(q[ma].size() < n / 2) q[ma].push({-(a[i][ma] - a[i][ma2]), {i, 1}});
			else
			{
				auto p = q[ma].top().second;
				int pma = maxx(p.first);int pma2 = nxtma(p.first,pma);int pma3 = las(pma, pma2);
				int use = p.second == 1 ? pma : p.second == 2 ? pma2 : pma3;
				int use2 = use == pma ? pma2 : pma3;
				if(a[i][ma] + a[p.first][use2] < a[i][ma2] + a[p.first][use]) q[ma2].push({-(a[i][ma2] - a[i][ma3]), {i, 2}});
				else
				{
					 q[ma].pop(); q[use2].push({-(a[p.first][use] - a[p.first][use2]), {p.first, use2 == pma2 ? 2 : 3}});
					 q[ma].push({-(a[i][ma] - a[i][ma2]), {i, 1}});
				}
			}
		}
		for(int i = 1;i <= 3;i ++)
			while(!q[i].empty())
			{
				auto p = q[i].top().second;
				int pma = maxx(p.first);int pma2 = nxtma(p.first, pma);int pma3 = las(pma, pma2);
				ans += a[p.first][p.second == 1 ? pma : p.second == 2 ? pma2 : pma3], q[i].pop();			
			}
		cout << ans << '\n';
	}
	
	return 0;
}

/*
µ÷ÊÔ 2 h£¬ÎÒÕæÀ÷º¦ 
*/
