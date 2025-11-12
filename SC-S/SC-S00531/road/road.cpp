#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[1000006],fa[1000006],ans;
struct LU{
	int u,v,w;
}lu[1500000];
bool cmp(LU&a,LU&b){return a.w<b.w;}
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&lu[i].u,&lu[i].v,&lu[i].w);
	for(int i=1;i<=k;i++){
		int x;
		scanf("%*d");
		for(int j=1;j<=n;j++){
			scanf("%d",a+j);
			if(!a[j])x=j;
		}
		for(int j=1;j<=n;j++){
			lu[++m].u=x;
			lu[m].v=j;
			lu[m].w=a[j];
		}
	}
	sort(lu+1,lu+m+1,cmp);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		if(find(lu[i].u)!=find(lu[i].v)){
			fa[find(lu[i].u)]=find(lu[i].v);
			ans+=lu[i].w;
		}
	}
	printf("%d",ans);
}