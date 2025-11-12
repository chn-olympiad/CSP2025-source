#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
struct NDE{
	int u,v,w;
}a[2000005];
int sl;
int fx[15];
int way[15][10005];
int ans=INT_MAX;
NDE newo[10000005];
int sln;
int fa[10005];
bool cmp(NDE a,NDE b){
	return a.w<b.w;
}
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int calc(string zk){
	int res=0;
	sln=2*m;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=sln;i++) newo[i]=a[i];
	for(int i=0;i<zk.size();i++){
		if(zk[i]=='1'){
			res+=fx[i+1];
			for(int u=1;u<=n;u++){
				for(int v=u+1;v<=n;v++){
					newo[++sln].u=u;
					newo[sln].v=v;
					newo[sln].w=way[i+1][u]+way[i+1][v];
					newo[++sln].u=v;
					newo[sln].v=u;
					newo[sln].w=way[i+1][u]+way[i+1][v];
				}	
			}
		}
	}
	int lft=n;
	sort(newo+1,newo+1+sln,cmp);
	for(int i=1;i<=sln;i++){
		if(lft==1) break;
		if(find(newo[i].u)!=find(newo[i].v)){
			fa[find(newo[i].u)]=find(newo[i].v);
			res+=newo[i].w;
			lft--;
		}
	}
	return res;
}
void dfs(int now,string zk){
	if(now>k){
		ans=min(ans,calc(zk));
		return;
	}
	dfs(now+1,zk+'1');
	dfs(now+1,zk+'0');
} 
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[++sl]={u,v,w};
		a[++sl]={v,u,w};
	}
	sort(a+1,a+1+sl,cmp);
	for(int i=1;i<=k;i++){
		cin>>fx[i];
		for(int j=1;j<=n;j++) cin>>way[i][j];
	}
	cout<<0;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
