#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define PLL pair<long long,long long>
#define VLL vector<long long>
#define PB push_back
const int N=1145;
ll n,m,u,v,k,val,ans=0;
ll a[N];
ll d[N];
bool vis[N];
struct zy {
	ll v,val;
};
vector<zy>g[N];
void spfa() {
	memset(d,0x3f,sizeof d);
	d[0]=0;
//	priority_queue<ll, vector<ll>,greater<ll> >q;
	queue<ll>q;
	q.push(0ll);
	vis[0]=1;
	while(q.size()) {
		ll x=q.front();
		q.pop();
		vis[x]=0;
		for(auto tmp:g[x]) {
			ll w=tmp.val;
			ll v=tmp.v;
			if(d[v]>d[x]+w) {
				d[v]=d[x]+w;
				if(x>n) ans+=d[x];
				if(!vis[v]) {
					q.push(v);
					vis[v]=1;
				}
			}
		}
	}
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1; i<=m; i++) {
		scanf("%lld%lld%lld",&u,&v,&val);
		g[u].PB({v,val});
		g[v].PB({u,val});
	}
	for(int i=1; i<=k; i++) {
		scanf("%lld",&u);
		g[0].PB({n+i,u});
		for(int j=1; j<=n; j++) {
			scanf("%lld",&val);
			g[n+i].PB({j,val});
		}
	}
	g[0].PB({1,0});
	spfa();
	for(int i=1; i<=n; i++) ans+=d[i];
	for(int i=1; i<=n+k; i++) cout<<d[i]<<endl;
	printf("%lld\n",ans);
	return 0;
}

