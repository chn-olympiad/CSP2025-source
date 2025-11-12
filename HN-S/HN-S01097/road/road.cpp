#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define debug(a) cout<<#a<<"="<<a<<"\n";
using namespace std;
const long long N=1e4+17;
int n,m,k,f[N],v[N];
long long ans=1e18;
struct node{
	int to,w;
};
vector<node> g[N];
vector<int> la[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,m){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	rep(i,1,k){
		int y;
		scanf("%d",&y);
		rep(j,1,n){
			int x;
			scanf("%d",&x);
			if(j==0) continue;
			g[i+n].push_back({j,x});
			g[j].push_back({i+n,x+y});
		}
	}
	rep(i,0,n+k) f[i]=2e9;
	f[1]=0;
	rep(i,1,n+k){
		int id=0;
		rep(j,1,n+k){
			if(v[j]==0&&f[j]<f[id]) id=j;
		}
		v[id]=1;
		for(int j=0;j<g[id].size();j++){
			int y=g[id][j].to;
			if(v[y]==0){
				if(g[id][j].w<f[y]){
					f[y]=g[id][j].w;
					la[y].clear();
					la[y].push_back(id);
				}
				else if(g[id][j].w==f[y]){
					la[y].push_back(id);
				}
			}
		}
	}
	int s=(1<<k)-1;
	rep(i,0,s){
		bool flag=1;
		rep(j,2,n){
			bool qq=0;
			for(int k=0;k<la[j].size();k++){
				if(la[j][k]<=n){
					qq=1;
					break;
				}
				else if(i&(1<<(la[j][k]-n-1))){
					qq=1;
					break;
				}
			}
			if(qq==0){
				flag=0;
				break;
			}
		}
		if(flag){
			long long sum=0;
			rep(j,1,n+k){
				if(j<=n) sum+=f[j];
				else if(i&(1<<(j-n-1))){
					sum+=f[j];
				}
			}
			ans=min(ans,sum);
		}
	}
	printf("%lld\n",ans); 
    return 0;
}
