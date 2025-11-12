//余诗琪 GZ-S00031 贵阳市第三实验中学
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mx=1e6+5;
int n,m,k,a[11][mx],fa[mx],siz[mx],ans;
struct edge {
	int u,v,w;
	bool operator<(const edge&p)const{
		return w<p.w;
	}
}e[mx];
bool flag=1;
int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx!=fy) fa[fx]=fy,siz[fy]+=siz[fx];
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i,siz[i]=1;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[i]={u,v,w};
	}
	for(int i=1; i<=k; i++)
		for(int j=0; j<=n; j++){
			cin>>a[i][j];
			if(a[i][j]!=0) flag=0;
		}
	if(flag&&k!=0){
		cout<<0;
		return 0;
	}
	sort(e+1,e+m+1);
	for(int i=1;i<=m;i++){
		ans+=e[i].w;
		merge(e[i].u,e[i].v);
		if(siz[find(e[i].u)]==n){
			cout<<ans;
			return 0;
		}
	}
	return 0;
}
