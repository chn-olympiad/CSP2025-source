#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node{
	int u,v,w;
}g[N];
int n,m,k,p,c[N],a[N],f[N];
bool all=1;
bool cmp(node x,node y){
	return x.w<y.w;
}
int find(int x){
	return f[x]!=x?find(f[x]):f[x];
}
int kruskal(){
	sort(g+1,g+m+1,cmp);
	int cnt=0,sum=0;
	for(int i=1;i<=m;i++){
		int fu=find(g[i].u),fv=find(g[i].v);
		if(fu!=fv){
			f[fu]=fv;
			sum=sum+g[i].w+(fu>n?c[fu-n]:0);
			cnt++;
		}
		if(cnt==n-1)break;
	}
	return sum;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&g[i].u,&g[i].v,&g[i].w);
	}
	p=n;
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			for(int k=j-1;k>=1;k--){
				g[++m]={j,k,a[j]+a[k]+c[i]};
			}
		}
	}
	for(int i=1;i<=n;i++)f[i]=i;
	printf("%d",kruskal());
}
