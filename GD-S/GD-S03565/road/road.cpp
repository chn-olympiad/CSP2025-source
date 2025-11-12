#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int maxn=1e4+5,maxk=1e1+5,maxm=1e6+5;
int n,m,k,ul[maxm],vr[maxm],fa[maxn],id[maxm];
ll val[maxm],c[maxn],a[maxk][maxn];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int xx=find(x),yy=find(y);
	if(xx!=yy) fa[xx]=yy;
}
bool cmp(int x,int y){
	return val[x]<val[y];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++) scanf("%d%d%lld",&ul[i],&vr[i],&val[i]),id[i]=i;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[i][j]); 
			if(!c[i]){
				ul[++m]=i,vr[m]=j,val[m]=a[i][j]; 
			}
		}
	}
	sort(id+1,id+m+1,cmp);
	ll ans=0;
	for(int w=1;w<=m;w++){
		int i=id[w];
		int u=ul[i],v=vr[i];
		if(find(u)==find(v)) continue;
		merge(u,v);
		ans+=val[i];
	}
	printf("%lld\n",ans);
	return 0;
}
