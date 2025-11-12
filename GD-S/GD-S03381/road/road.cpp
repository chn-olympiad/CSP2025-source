#include<bits/stdc++.h>
using namespace std;
const int N=10002;
int n,m,k,u,v,w,c[11],a[N],fa[N];
long long f[1<<10];
int find(int k){return fa[k]==k?k:fa[k]=find(fa[k]);}
struct edge{
	int u,v,w;
	bool operator<(edge o)const{return w<o.w;}
}e[11][N],E[1<<10][N];
long long solve(int k,vector<edge>&e){
	for(int i=1;i<=n;i++)fa[i]=i;
	long long cnt=0,ans=0;
	for(auto i:e)if((u=find(i.u))!=(v=find(i.v))){
		fa[u]=v,E[k][++cnt]=i,ans+=i.w;
		if(cnt==n-1)return ans;
	}
	exit(-1);
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	vector<edge>ve;
	for(int i=1;i<=m;i++)cin>>u>>v>>w,ve.push_back({u,v,w});
	sort(ve.begin(),ve.end());
	long long ans=solve(0,ve);
	for(int i=1;i<=k;i++){
		cin>>c[i];
		int u=1;
		for(int v=1;v<=n;v++){
			cin>>a[v];
			if(a[v]<a[u])u=v;
		}
		c[i]+=a[u];
		for(int v=1,j=0;v<=n;v++)if(u!=v)e[i][++j]={u,v,a[v]};
		sort(e[i]+1,e[i]+n);
	}
	ve.resize(n+n-2);
	for(int S=1;S<1<<k;S++){
		int s=S^(S&-S),i=__lg(S&-S)+1;
		f[S]=f[s]+c[i];
		merge(E[s]+1,E[s]+n,e[i]+1,e[i]+n,ve.begin());
		ans=min(ans,solve(S,ve)+f[S]);
	}
	cout<<ans;
}
