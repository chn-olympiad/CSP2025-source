#include<bits/stdc++.h>
//#define int long long 
using namespace std;
const int N=1e6+5;
int n,m,k,c[15],a[15][N],f[N];
long long ans;
struct EDDD{int u,v,w;}e[N*2];
int fid(int x){return (x!=f[x])?f[x]=fid(f[x]):f[x];}
bool unin(int x,int y){
	x=fid(x),y=fid(y);
	if(x!=y){
		f[y]=x;
		return 1;
	}
	return 0;
}
bool cmp(EDDD x,EDDD y){return x.w<y.w;}
int U[N],V[N],W[N];
bool t[N];
void dfs(int st){
	if(st>k){
		for(int i=1;i<=m;++i)e[i]={U[i],V[i],W[i]};
		for(int i=1;i<=n+k;++i)f[i]=i;
		long long res=0;
		int tot=m;
		for(int i=1;i<=k;++i){
			if(t[i]){
				for(int j=1;j<=n;++j)e[++tot]={i+n,j,a[i][j]};
				res+=c[i];
			}
		}
		sort(e+1,e+tot+1,cmp);
		for(int i=1;i<=tot;++i)if(unin(e[i].u,e[i].v))res+=e[i].w;
		ans=min(ans,res);
		return;
	}
	t[st]=1;
	dfs(st+1);
	t[st]=0;
	dfs(st+1);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;++i)f[i]=i;
	for(int i=1;i<=m;++i)cin>>U[i]>>V[i]>>W[i];
	bool _1=1;
	for(int i=1;i<=k;++i){
		cin>>c[i];
		if(c[i])_1=0;
		for(int j=1;j<=n;++j){
			cin>>a[i][j];
			if(a[i][j])_1=0;
		}
	}
	if(k==0){
		for(int i=1;i<=m;++i)e[i]={U[i],V[i],W[i]};
		sort(e+1,e+m+1,cmp);
		for(int i=1;i<=m;++i)if(unin(e[i].u,e[i].v))ans+=e[i].w;
		cout<<ans;
		return 0;
	}
	if(_1){
		cout<<0;
		return 0;
	}
	ans=1e18;
	dfs(1);
	cout<<ans;
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