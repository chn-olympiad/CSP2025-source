#include"bits/stdc++.h"
using namespace std;
struct node{
	int u,v,w;
	bool operator<(const node &x) const {
		return w<x.w;
	}
};
vector<node>v;
int fa[1000005];
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
void merge(int x,int y){
	x=find(x);
	y=find(y);
	if(fa[x]!=fa[y])
		fa[x]=y;
	return;
}
int n,m,k;
int c[10005];
int a[10005][15];
int kruskal(){
	sort(v.begin(),v.end());
	int cnt=0,ans=0;
	for(auto x:v){
		int tmp1=x.u;
		int tmp2=x.v;
		int tmp3=x.w;
		if(find(tmp1)!=find(tmp2)){
			merge(tmp1,tmp2);
			cnt++;
			ans+=tmp3;
		}
		if(cnt==n-1)
			break;
	}
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=0;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++){
		int u,vv,w;
		cin>>u>>vv>>w;
		v.push_back({u,vv,w});
	}
	bool f=true;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i])
			f=false;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j])
				f=false;
		}
	}
	if(f){
		puts("0");
		return 0;
	}
	printf("%d\n",kruskal());
	return 0;
}
