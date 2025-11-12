#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const ll N = 1e6+20;
const ll inf = 1e18;
struct e{
	ll u,v,w;
};
bool cmp(e a,e b)
{
	return a.w < b.w; 
}
ll fa[N];
vector<e>g;
ll n,m,k;
ll vi[12][N];
ll vb[12];
void init()
{
	for(ll i = 1; i <= n+k; i++)
	{
		fa[i] = i;
	}
}
ll get(ll x)
{
	if(fa[x]==x)
	{
		return x;
	}
	return fa[x] = get(fa[x]);
}
void add(ll x,ll y)
{
	x = get(x);
	y = get(y);
	fa[x] = fa[y];
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll qans = inf;
	cin >> n >> m >> k;
	for(ll i = 1; i <= m ; i++)
	{
		ll u,v,w;
		cin >> u >> v >> w;
		g.push_back({u,v,w});
	}
	bool ok = true;
	for(ll i = 1; i <= k ; i++)
	{
		cin >> vb[i];
		if(vb[i] != 0) ok = false;
		for(ll j = 1; j <= n ; j++)
		{
			cin >> vi[i][j];
			if(vi[i][j] != 0) ok = false;
		}
			
	}
	if(ok)
	{
		cout<<0;
		return 0;
	}
	ll  up = (1<<k)-1;
	for(ll i = 0; i <= up; i++)
	{
		init();
		ll f= i,op = k;
		vector<e>h = g;
		ll ans = 0;
		int cnt = 0;
		while(f)
		{
			if(f&1)
			{
				ans += vb[op];
				for(ll i = 1; i <= n ; i++)
				{
					h.push_back({n+op,i,vi[op][i]});
				}
				cnt++;
			}
			f >>= 1;
			op--;
			
 		}	
		sort(h.begin(),h.end(),cmp);
		int cn =0;
		for(auto y : h)
		{
			
			if(get(y.u) == get(y.v)) continue;
			add(y.u,y.v);
			cn++;
			ans += y.w;
			if(cn == n+cnt-1) break;
		}
		qans = min(qans,ans);
				
	}
	cout<<qans;
	return 0;
}