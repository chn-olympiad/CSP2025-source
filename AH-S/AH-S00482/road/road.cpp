#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M = 1e6 + 5;
typedef pair<ll , ll> PII;
struct node
{
	ll v , w , next;
	node()
	{
		w = next = 0;
	}
	node(ll a , ll b , ll c)
	{
		v = a , w = b , next = c;
	}
}adj[M];
ll h[M] , dist[M] , idx = 1;
bool st[M];
ll c[20] , a[20][M];
void insert(ll x , ll y , ll z)
{
	adj[idx] = node(y , z , h[x]);
	h[x] = idx++;
}
void dij()
{
	memset(dist , 0x3f3f3f3f , sizeof(dist));
	dist[1] = 0;
	priority_queue<PII , vector<PII> , greater<PII>> heap;
	heap.push({0 , 1});
	while(heap.size())
	{
		PII k = heap.top();
		heap.pop();
		ll ver = k.second;
		ll distance = k.first;
		if(st[ver])
			continue;
		st[ver] = 1;
		for(ll i = h[ver] ; i != 0 ; i = adj[i].next)
		{
			ll j = adj[i].next;
			if(dist[j] > adj[i].w + distance)
			{
				dist[j] = adj[i].w + distance;
				heap.push({dist[j] , j});
			}
		}
	}
	return;
}
int main()
{
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	ll n , m , k , ans = 0;
	cin >> n >> m >> k;
	for(ll i = 1 ; i <= m ; i++)
	{
		ll u , v , w;
		cin >> u >> v >> w;
		insert(u , v , w);
		insert(v , u , w);
		ans += w;
	}
	for(ll i = 1 ; i <= k ; i++)
	{
		cin >> c[i];
		for(ll j = 1 ; j <= n ; j++)
			cin >> a[i][j];
	}
	dij();
	cout << ans;
	return 0;
}
