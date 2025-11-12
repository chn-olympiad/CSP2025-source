#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
	int u,v,w;
	bool operator<(const node x)const{
		return w<x.w;
	}
};
vector<node>g;
int n,m,k,c[10010],a[20][10010];
int fa[10010];
void init(){
	for(int i=1;i<=n;i++)fa[i]=i;
}
int get(int x){
	return fa[x]==x?x:fa[x]=get(fa[x]);
}
void merge(int x,int y){
	int a=get(x),b=get(y);
	fa[b]=a;
}
ll kaku(){
	sort(g.begin(),g.end());
	ll cnt=0,res=0;
	for(int i=0;i<m;i++){
		int u=g[i].u,v=g[i].v,w=g[i].w;
		if(get(u)==get(v))continue;
		res+=w;
		merge(u,v);
		cnt++;
		if(cnt==n-1)return res;
	}
	return -1;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	init();
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		g.push_back({u,v,w});
		g.push_back({v,u,w});
	}
	for(int i=1;i<=k;i++){
		scanf("%d",c+i);
		for(int j=1;j<=n;j++)scanf("%d",a[i]+j);
	}
	if(k==0){
		printf("%lld",kaku());
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			int w=1e9;
			for(int l=1;l<=k;l++)w=min(w,a[l][i]+a[l][j]+c[l]);
			g.push_back({i,j,w});
			g.push_back({j,i,w});
		}
	}
	printf("%lld",kaku());
	return 0;
}