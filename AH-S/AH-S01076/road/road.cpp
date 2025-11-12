#include"bits/stdc++.h"
using namespace std;
const int N=1e4+5,M=1e6+5;
struct node{
	int u,v,w;
	bool operator<(node b){
		return w<b.w;
	}
}e[M+N*10],t[M];
int f[N+15],n,m,k,h[15][N];
bitset<N>vis[15];
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
int work(int x){
	int ans=0,cnt=m;
	iota(f+1,f+n+16,1);
	copy(t+1,t+m+1,e+1);
	for(int i=1;i<=k;++i)
	if(x&(1<<(i-1))){
		ans+=h[i][0];
		for(int j=1;j<=n;++j){
			e[++cnt]=node{n+i,j,h[i][j]};
		}	
	}
	sort(e+1,e+cnt+1);
	for(int i=1;i<=cnt;++i){
		int fu=find(e[i].u),fv=find(e[i].v);
		if(fu!=fv){
			ans+=e[i].w;
			f[fu]=fv;
		}
	}
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;++i){
		cin>>u>>v>>w;
		t[i]={u,v,w};
	}
	for(int i=1;i<=k;++i)
	for(int j=0;j<=n;++j)
	cin>>h[i][j];
	int ans=INT_MAX;
	for(int i=0;i<(1<<k);++i){
		ans=min(ans,work(i));
	}
	cout<<ans<<"\n";
}
