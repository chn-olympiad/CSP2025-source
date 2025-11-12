//GZ-S00499 贵阳市第一中学 黄世杰
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
const int N=1e4+10,M=1e6+10;
struct Edge{
	int u,v,w;
}e[12*M];
int tot;
int vis[20],mo[20],fa[12+N];
priority_queue<pii,vector<pii>,greater<pii>>q;
int n,m,k;
long long ans;

bool cmp(Edge x,Edge y){
	return x.w<y.w;
}

int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n+k;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		e[++tot].u=u,e[tot].v=v,e[tot].w=w;	
	}
	for(int i=1;i<=k;i++){
		int cw;scanf("%d",&cw);
		for(int j=1;j<=n;j++){
			int w;scanf("%d",&w);
			e[++tot].u=n+i,e[tot].v=j,e[tot].w=w;	
		}
	}
	sort(e+1,e+tot+1,cmp);
	for(int i=1;i<=tot;i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(find(v)==find(u))continue;
		fa[find(u)]=find(v);
		ans+=w;
		if(v>n)vis[v-n]++,mo[v-n]+=w;
		if(u>n)vis[u-n]++,mo[u-n]+=w;
	}
	for(int i=1;i<=k;i++){
		if(vis[i]==1)ans-=mo[i]; 
	}
	cout<<ans<<endl;
	return 0;
} 
