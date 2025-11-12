#include<bits/stdc++.h>
using namespace std;
struct edge{
	int from,to,w;
}e[2000005];
int n,m,cnt,fa[10105],k,ans,c[15],win;
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		e[++cnt]={x,y,z};
	}for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			int x;
			scanf("%d",&x);
			e[++cnt]={i+n,j,x};
		}
	}sort(e+1,e+cnt+1,cmp);
	for(int i=1;i<=n+k;i++)fa[i]=i;
	for(int i=1;i<=cnt;i++){
		int fx=find(e[i].from),fy=find(e[i].to);
		if((fx==e[i].from and e[i].from<=n) or (fy==e[i].to and e[i].to<=n))win++;
		if(fx!=fy)fa[fx]=find(fy),ans+=e[i].w;
		if(win==n)break;
	}cout<<ans<<endl;
}
