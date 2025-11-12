#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const int N=1e4+10,M=1e6+10;
int fa[N];
struct node {
	int u,v,w;
	int d=0;
}a[M];
int b[N],g[15];
bool vis[15];
long long ans;
bool cmp(node a,node b){
	return a.w<b.w;
}
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&g[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&b[j]);
			for(int k=1;k<j;k++){
				a[++m].u=k;
				a[m].v=j;
				a[m].w=b[j]+b[k]+g[i];
				a[m].d=i;
			}
		}
	}
	sort(a+1,a+1+m,cmp);
	int t=0;
	for(int i=1;i>=0;i++){
		if(t==n-1)break;
		int fx=find(a[i].u),fy=find(a[i].v);
		if(fx!=fy){
			fa[fx]=fy;
			ans+=a[i].w;
			if(a[i].d!=0){
				if(vis[a[i].d])ans-=g[a[i].d];
				else vis[a[i].d]=1;
			}
			t++;
		}
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
