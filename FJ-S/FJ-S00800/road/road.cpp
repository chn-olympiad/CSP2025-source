#include <bits/stdc++.h>
#define ll long long
using namespace std;
constexpr int maxn = 1e4 + 5;
constexpr int maxm = 1e6 + 5;
int n , m , k ;
ll dis[maxn];
bool vis[maxn];
vector<pair<int , int> > e[maxm];
inline void kruskal(int s)
{
	priority_queue<pair<int , int> , vector<pair<int , int> > , less<int> > p_q;
	p_q.push({s , 0});
	while(!p_q.empty())
	{
		auto f = p_q.top();
		p_q.pop();
		int now = f.first;
		for(int i = 0 ; i < e[now].size() ; i ++)
		{
			int v = e[now][i].first;
			int w = e[now][i].second;
			if(dis[now] + w < dis[v])
			{
				dis[v] = dis[now] + w;
				p_q.push({v , -dis[v]});
			} 
		}
	} 
	return ;
}
int main()
{
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	for(int i = 1 ; i <= m ; i ++)
	{
		int u , v , w;
		cin >> u >> v >> w;
		e[0].push_back({u , 0});
		e[u].push_back({v , w});
		e[v].push_back({u , w});
	{ 
	for(int i = 1 ; i <= k ; i ++)
	{
		int c;
		cin >> c;
		for(int j = 1 ; j <= n ; j ++)
		{
			int w;
			cin >> w;
			e[0].push_back({i + n , c});
			e[i + n].push_back({j , w});
			e[j].push_back({i + n , w});
		}
	}
	kruskal(0);
	ll ans = 0x3f3f3f3f;
	for(int i = 1 ; i <= n ; i ++)
	{
		ans = min(ans , dis[i]);
	}
	cout << ans << '\n';
	return 0;
}

