#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long ll;
const int MAXN=1e4+5;
const int MAXM=2e6+5;
int n,m,k;
struct Edge{
	int u,v;
	ll w;
	bool operator<(const Edge&K)const{
		return w<K.w;
	}
}e[MAXM];
ll a[11][MAXN];
namespace Baoli{
	int f[MAXN*2],sz[MAXN*2];
	void init(){
		rep(i,1,n+k){
			f[i]=i;
			if(i<=n){
				sz[i]=1;
			}
		};
	};
	int find(int u){
		return f[u]==u?u:f[u]=find(f[u]);
	};
	void merge(int u,int v){
		f[u]=v;
		sz[v]+=sz[u];
	};
	void Do(){
		int tot=m;
		rep(i,1,k){
			rep(j,1,n){
				e[++tot]={n+i,j,a[i][j]};
			};
		};
		sort(e+1,e+tot+1);
		//~ rep(i,1,tot){
			//~ cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<"\n";
		//~ };
		ll ans=1e18;
		rep(s,0,(1<<k)-1){
			ll val=0;
			rep(j,0,k-1){
				if((s>>j)&1){
					val+=a[j+1][0];
				}
			};
			init();
			//~ cout<<s<<" "<<val<<"\n";
			rep(j,1,tot){
				if(e[j].u>n&&(!((s>>(e[j].u-n-1))&1))){
					continue;
				}
				int u=find(e[j].u),v=find(e[j].v);
				if(u==v){
					continue;
				}
				merge(u,v);
				val+=e[j].w;
				if(sz[v]==n){
					ans=min(ans,val);
					break;
				}
				if(val>=ans){
					break;
				}
			};
			//~ cout<<"\t"<<val<<"\n";
		};
		cout<<ans<<"\n";
	};
}
namespace ZJ{
	int f[MAXN*2],sz[MAXN*2];
	void init(){
		rep(i,1,n+k){
			f[i]=i;
			if(i<=n){
				sz[i]=1;
			}
		};
	};
	int find(int u){
		return f[u]==u?u:f[u]=find(f[u]);
	};
	void merge(int u,int v){
		f[u]=v;
		sz[v]+=sz[u];
	};
	void Do(){
		int tot=0;
		init();
		sort(e+1,e+m+1);
		rep(i,1,m){
			int u=find(e[i].u),v=find(e[i].v);
			if(u!=v){
				merge(u,v);
				e[++tot]=e[i];
			}
		};
		rep(i,1,k){
			rep(j,1,n){
				e[++tot]={n+i,j,a[i][j]};
			};
		};
		sort(e+1,e+tot+1);
		//~ rep(i,1,tot){
			//~ cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<"\n";
		//~ };
		ll ans=1e18;
		rep(s,0,(1<<k)-1){
			ll val=0;
			rep(j,0,k-1){
				if((s>>j)&1){
					val+=a[j+1][0];
				}
			};
			init();
			//~ cout<<s<<" "<<val<<"\n";
			rep(j,1,tot){
				if(e[j].u>n&&(!((s>>(e[j].u-n-1))&1))){
					continue;
				}
				int u=find(e[j].u),v=find(e[j].v);
				if(u==v){
					continue;
				}
				merge(u,v);
				val+=e[j].w;
				if(sz[v]==n){
					ans=min(ans,val);
					break;
				}
				if(val>=ans){
					break;
				}
			};
			//~ cout<<"\t"<<val<<"\n";
		};
		cout<<ans<<"\n";
	};
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	rep(i,1,m){
		cin>>e[i].u>>e[i].v>>e[i].w;
	};
	rep(i,1,k){
		cin>>a[i][0];
		rep(j,1,n){
			cin>>a[i][j];
		};
	};
	if(k<=5){
		Baoli::Do();
		return 0;
	}
	ZJ::Do();
	return 0;
}
