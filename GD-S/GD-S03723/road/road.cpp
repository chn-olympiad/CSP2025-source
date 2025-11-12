#include<bits/stdc++.h>
using namespace std;
#define N 20001 
int n,m,k;
vector<pair<int,int> > G[N];
int c[N];
long long dis[N],ans=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	memset(c,0,sizeof c);
	memset(dis,0x3f,sizeof dis);
	for(int i=1,x,y,z;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		G[x].push_back(make_pair(y,z));
		G[y].push_back(make_pair(x,z));
	}
	for(int i=1;i<=k;i++){
		scanf("%d",c+i+n);
		for(int j=1,x;j<=n;j++){
			scanf("%d",&x);
			G[j].push_back(make_pair(i+n,x));
			G[i+n].push_back(make_pair(j,x));
		}
	}
	int u=1;
	dis[u]=0;
	int cnt=1;
	while(cnt<n){
		int p=0;
		for(pair<int,int> v:G[u]){
			dis[v.first]=min(dis[v.first],(long long)(v.second+c[v.first]));
		}
		for(int i=1;i<=n+k;i++){
			if(dis[i]!=0&&dis[i]<dis[p]){
				p=i;
			}
		}
		if(c[p]==0) ++cnt;
		ans+=dis[p];
		dis[p]=0;
		u=p;
	}
	printf("%lld",ans);
	return 0;
} 
