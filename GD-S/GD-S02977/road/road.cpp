#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[20][10010],tot,ans;
int fa[10010];
struct node{
	int from,to,w;
}a[1000010];
int cmp(node a,node b){
	return a.w<b.w;
}
int fand(int x){
	if(fa[x]==x) return x;
	return fa[x]=fand(fa[x]);
}
void he(int a,int b){
	int p=fand(a);
	int q=fand(b);
	fa[p]=q;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a[i].from,&a[i].to,&a[i].w);
	}
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i][0]);
		for(int j=1;j<=n;j++){
			scanf("%d",&c[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	int i=1;
	while(tot!=n-1){
		if(fand(a[i].from)!=fand(a[i].to)){
			ans+=a[i].w;
			he(a[i].from,a[i].to);
			tot++; 
		}
		i++;
	}
	printf("%d",ans);
	return 0;
}
