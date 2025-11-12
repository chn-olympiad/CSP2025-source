#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+10,M=2e6+10;

struct Ed{
	int u,v,w;
}e[M];

int n,m,k;
int fa[N];
int c[11],a[11][N];
int l[1010][1010];

bool cmp(Ed x,Ed y){
	return x.w<y.w;
}

int find(int x){
	if(fa[x]!=x)fa[x]=find(fa[x]);
	return fa[x];
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>e[i].u>>e[i].v>>e[i].w;
	if(!k){
		sort(e+1,e+1+m,cmp);
		for(int i=1;i<=n;i++)fa[i]=i;
		int ans=0;
		for(int i=1;i<=m;i++){
			int x=find(e[i].u),y=find(e[i].v);
			if(x==y)continue;
			fa[x]=y;
			ans+=e[i].w;
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)l[i][j]=1e15;
		for(int i=1;i<=k;i++)
			for(int j=1;j<=n;j++)
				for(int o=1;o<=n;o++)
					l[j][o]=min(l[j][o],a[i][j]+a[i][o]);
		for(int i=1;i<=m;i++)l[e[i].u][e[i].v]=l[e[i].v][e[i].u]=min(l[e[i].u][e[i].v],e[i].w);
		int cnt=0;
		for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)e[++cnt]={i,j,l[i][j]};
		for(int i=1;i<=cnt;i++)fa[i]=i;
		sort(e+1,e+1+cnt,cmp);
		int ans=0;
		for(int i=1;i<=cnt;i++){
			int x=find(e[i].u),y=find(e[i].v);
			if(x==y)continue;
			fa[x]=y;
			ans+=e[i].w;
		}
		cout<<ans;
	
	
	return 0;
}
