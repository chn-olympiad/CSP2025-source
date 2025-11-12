#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,c[15],a[15][10005];
long long f[10005][15],ans=LONG_MAX;
vector<pair<int,int> > g[10005]; //目的地，权值
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&u,&v,&w);
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&w);
			g[n+i].push_back({j,w});
			g[j].push_back({n+i,w});
		}
	}
	for(int i=2;i<=n;i++){
		for(int j=0;j<=k;j++){
			int sum=0,r=INT_MAX,r2=INT_MAX,flg=0;
			for(int u=1;u<i;u++){
				for(auto v:g[u]){
					if(v.first==i) r=min(r,v.second);
					else if(v.first>n&&v.first<=n+j){
						r2=min(r2,v.second);
						flg=1;
					}
				}
			}
			for(int u=n+1;u<=n+j;u++){
				for(auto v:g[u]){
					if(v.first==i) r=min(r,v.second);
					else if(v.first>n&&v.first<=n+j){
						r2=min(r2,v.second);
						flg=1;
					}
				}
			}
			if(r==INT_MAX) continue;
			f[i][j]=min(f[i-1][j],j?f[i][j-1]+flg*c[j]:INT_MAX)+r+r2;
			if(i==n) ans=min(ans,f[i][j]);
		}
	}
	cout<<ans;
	return 0;
}

