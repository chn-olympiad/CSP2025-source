#include<bits/stdc++.h>
using namespace std;
const int MAXN=20005,MAXM=1000105;
int n,m,k,fa[MAXN],cnte,cntn,ans;
struct Edge{
	int u,v,w;
}e[MAXM];
int find(int x){
	if(fa[x]==x)return x;
	else return fa[x]=find(fa[x]);
}
void unionn(int x,int y){
	x=find(x),y=find(y);
	if(x!=y){
		fa[x]=y;
		cnte++;
	}
}
bool cmp(Edge x,Edge y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	cntn=n;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	}
	if(k>0)cntn++;
	for(;cntn-n<=k;cntn++){
		int c;
		scanf("%d",&c);
		for(int j=1;j<=n;j++){
			scanf("%d",&c);
			if(c==0)unionn(cntn,j);
			else e[++m]={cntn,j,c};
		}
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(cnte==cntn-1)break;
		int u=e[i].u,v=e[i].v,w=e[i].w;
		u=find(u),v=find(v);
		if(u!=v)ans+=w,fa[u]=fa[v],cnte++;
	}
	printf("%d",ans);
	return 0;
}
