#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
struct node{
	int u,v,w;
}mp[1100005];
long long n,m,k,c[15],cnt,fa[11005],ans;
bool cmp(node a,node b){return a.w<b.w;}
int find(int x){
	if(x!=fa[x]) return fa[x]=find(fa[x]);
	return fa[x];
}
int kruskal(){
	int anss=0;
	sort(mp+1,mp+m+1,cmp);//!!!
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=1;i<=n;i++){
		int u=find(mp[i].u);
		int v=find(mp[i].v);
		if(u==v) continue;
		fa[u]=v;
		anss+=mp[i].w;
	}
	return anss;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		mp[i]=node{u,v,w};
	}
	ans=kruskal();
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1,x;j<=n;j++){
			cin>>x;
			mp[++cnt]=node{n+i,j,x};
		}
	}
	cout<<ans;
	return 0;
}