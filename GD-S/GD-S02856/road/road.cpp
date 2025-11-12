#include<bits/stdc++.h>
using namespace std;
long long n,m,k,ans[1100],vis[1100],minn=1e9,sz=0;
struct G{
	long long to,w;
};
vector<G> g[100005];
void dfs(long long x,long long sum,long long k){
	if(x<=n)k++;
	if(k==n){
		minn=min(minn,sum);
		return;
	}
	for(int i=0;i<g[x].size();i++){
		long long next=g[x][i].to,nom=g[x][i].w;
		if(next>n)nom+=1;
		if(vis[next]==0){
			vis[next]=1;
			ans[next]=ans[x]+nom;
			dfs(next,ans[next],k);
			vis[next]=0;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++)ans[i]=1e9;
	long long x,y,z;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		g[x].push_back({y,z});
		g[y].push_back({x,z});
	}
	
	long long p[12],pp,nn=n;
	for(int i=1;i<=k;i++){
		cin>>p[i];
		nn+=1;
		for(int j=1;j<=n;j++){
			cin>>pp;
			g[j].push_back({nn,pp});
			g[nn].push_back({j,pp});
		}
	}
	vis[1]=1;
	ans[1]=0;
	dfs(1,0,0);
	cout<<minn;
	return 0;
}
