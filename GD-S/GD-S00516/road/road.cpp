#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=1e4+25;
int n,m,k,fa[MAXN],v[15];
vector<array<int,3>> E,oE;
inline int find(int x){while(x^fa[x])x=fa[x]=fa[fa[x]];return x;}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;cin>>u>>v>>w;
		oE.push_back({w,u,v});
	}
	for(int i=1;i<=k;i++){
		cin>>v[i]; 
		for(int j=1;j<=n;j++){
			int w;cin>>w;oE.push_back({w,i+n,j});
		}
	}
	sort(oE.begin(),oE.end());
	for(int i=0;i<=n+k;i++) fa[i]=i;
	for(auto o:oE) if(o[1]>n||find(o[1])!=find(o[2])){
		if(o[1]<=n) fa[find(o[1])]=find(o[2]);
		E.push_back(o);
	}
	ll ans=1e18;
	for(int S=0;S<(1<<k);S++){
		ll sum=0;
		for(int i=0;i<=n+k;i++) fa[i]=i;
		for(int i=0;i<k;i++) if(S>>i&1) sum+=v[i+1];
		for(auto o:E) if((o[1]<=n||(S>>(o[1]-n-1)&1))&&find(o[1])!=find(o[2])){
			fa[find(o[1])]=find(o[2]);
			sum+=o[0];
		}
		ans=min(ans,sum);
	}
	cout<<ans<<'\n';
}

