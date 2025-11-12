#include<bits/stdc++.h>
using namespace std;
int n,m,k,kk,kkk;
long long ans;
int cnt;
int fa[10005];
struct node{
	int u;
	int v;
	int w;
}a[1000006];
bool cmp(node b1,node b2){
	return b1.w<b2.w;
}
int f1(int x){
	if(x==fa[x]) return x;
	return fa[x]=f1(fa[x]);
}
bool f2(int x,int y){
	int z1=f1(x);
	int z2=f1(y);
	if(z1!=z2){
		fa[z1]=z2;
		return true;
	} 
	return false;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);/*
	for(int i=1;i<=k;i++){
		scanf("%d",&kk);
		for(int j=1;j<=n;j++){
			scanf("%d",&kkk);
			++m;
			a[m].u=i;
			a[m].v=j;
			a[m].w=kkk;
		}
		
	}*/
	sort(a+1,a+m+1,cmp);
	//for(int i=1;i<=m;i++) printf("%d %d %d\n",a[i].u,a[i].v,a[i].w);
	for(int i=1;i<=m;i++){
		if(f2(a[i].u,a[i].v)){
			ans+=a[i].w;
			if(++cnt==m-1) break;
		}
	}
	printf("%lld",ans);
	return 0;
} 
