#include<bits/stdc++.h>
namespace zcy{
	using namespace std;
	const int MAXN=1e4+10;
	typedef long long ll;
	struct edge{
		int u;
		int v;
		ll w;
		edge(int v,ll w){
			this->v=v,this->w=w;
		}
		edge(int u,int v,ll w){
			this->u=u,this->v=v,this->w=w;
		}
		operator>(edge t)const{
			return w>t.w;
		}
	};
	vector<edge>g[MAXN+101];	//city no city
	int n,m,k;
	bool vis[MAXN+101];
	int c[101];
	ll lie[101];
	
	ll prim(){
		priority_queue<edge,vector<edge>,greater<edge>>pq;
		ll ans=0;
		pq.push({0,1,0});
		while(!pq.empty()){
			edge t=pq.top();
			pq.pop();
			if(vis[t.v])continue;
//			cout<<"T.w="<<t.w<<" t.v="<<t.v<<endl;
			vis[t.v]=1;
			ans+=t.w;
			if(t.v>MAXN)lie[t.v-MAXN]-=t.w;//Come to a country
			if(t.u>MAXN){
				if(lie[t.u-MAXN]==0)lie[t.u-MAXN]+=c[t.u-MAXN]>>1;
				else lie[t.u-MAXN]=0;//Come from a country
			}
			for(edge u:g[t.v]){
				if(!vis[u.v])pq.push({t.v,u.v,u.w});
			}
		}
//		cout<<"return "<<ans<<endl<<endl<<endl;
		return ans;
	}
	
	int main(){
		#ifndef debug
		freopen("road.in","r",stdin);
		freopen("road.out","w",stdout);
		#endif
		ios::sync_with_stdio(false);
		cin.tie(0);
		
		cin>>n>>m>>k;
		for(int i=1;i<=m;i++){
			int u,v;
			ll w;
			cin>>u>>v>>w;
			w<<=1;
			g[u].emplace_back(v,w);
			g[v].emplace_back(u,w);
		}
		for(int i=1;i<=k;i++){
			cin>>c[i];
			c[i]<<=1;
			for(int j=1;j<=n;j++){
				ll a;
				cin>>a;
				a<<=1;
				g[i+MAXN].emplace_back(j,a+c[i]/2);
				g[j].emplace_back(i+MAXN,a+c[i]/2);
			}
		}
		ll ans=prim();
		for(int i=1;i<=k;i++)ans+=lie[i];
		cout<<ans/2<<endl;
		return 0;
	}
}
int main(){
	zcy::main();
	return 0;
}
