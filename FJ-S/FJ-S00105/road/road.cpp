#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
const int M=1e4+10;

struct node{
	int u,v,w;
	bool flg=0;
}edge[N];

int n,m,k;
int cnt,ans;
int c[M];
int a[M][M];
int fa[N];

bool vis[N];

int find(int x){
	if(fa[x]!=x)fa[x]=find(fa[x]);
	return fa[x];
}

bool cmp(node x,node y){
	return x.w<y.w;
}

bool check(){//判断原先城市是否联通  
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=cnt;i++){
		if(edge[i].flg==0)continue;
		vis[edge[i].u]=1;
		vis[edge[i].v]=1;
	}
	for(int i=1;i<=m;i++)if(vis[i]==0)return 0;
	return 1;
}

int kruskal(){
	for(int i=1;i<=cnt;i++){
		edge[i].flg=0;
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	int sum=0;
	sort(edge+1,edge+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		if(check())break;
		int px=find(edge[i].u);
		int py=find(edge[i].v);
		if(px!=py){
			fa[py]=px;
			sum+=edge[i].w;
			edge[i].flg=1;
		}
	}
	return sum;
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	cnt=m;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			if(c[i]==0){
				edge[++cnt].u=i;
				edge[cnt].v=j;
				edge[cnt].w=a[i][j];
			}
		}
	}
	ans=kruskal();
	for(int i=1;i<=k;i++){
		if(c[i]==0)continue;
		for(int j=1;j<=n;j++){
			edge[++cnt].u=i;
			edge[cnt].v=j;
			edge[cnt].w=a[i][j];
			edge[cnt].flg=0;
		}
		int res=c[i]+kruskal();
		if(res<ans)ans=res;
		else cnt-=n;//删除有关边 
	}
	printf("%d",ans);
	return 0;
}
