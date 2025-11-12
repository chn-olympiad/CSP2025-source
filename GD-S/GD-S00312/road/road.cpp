#include<bits/stdc++.h>
using namespace std;
int n,m,fa[20005],k,c[15],d[15][10005],x,y,s,mi,f;
struct nood{
	int u,v,w;
};
nood a[2000005],b[20005];
bool cmp(nood a,nood b){
	return a.w<b.w;
}
int find(int x){
	if(fa[x]==x)return x;
	fa[x]=find(fa[x]);
	return x;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
	}
	for(int i=1;i<=k;i++)scanf("%d",&c[i]);
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)scanf("%d",&d[i][j]);
	}
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=m;i++)
	{
		x=find(a[i].u);y=find(a[i].v);
		if(x!=y){
			fa[x]=y;s+=a[i].w;b[++f].u=a[i].u;
			b[f].v=a[i].v;b[f].w=a[i].w;
		}
	}
	if(k==0){
		cout<<s;return 0;
	}
	cout<<0;
	return 0;
}
