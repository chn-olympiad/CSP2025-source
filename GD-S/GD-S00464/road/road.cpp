#include<bits/stdc++.h>
using namespace std;
const long long N=2e6+5,M=1e4+5;
long long n,m,k;
struct edge{
	long long u,v,w;
	friend bool operator<(edge x,edge y){
		return x.w<y.w;
	}
}fp[M],op[N];
long long c[15],a[15][M];
long long f[M+20];
long long idx=0;
long long find(long long x){
	return f[x]==x?f[x]=x:find(f[x]);
}
void un(long long u,long long v){
	long long fu=find(u),fv=find(v);
	f[fv]=fu;
}
long long ans=1e18;
bool sav[N]; 
void kruskal(){
	long long cn=0;
	for(int i=1;i<=m;i++){
		long long u=op[i].u,v=op[i].v;
		if(find(u)==find(v)) continue;
		un(u,v);sav[i]=1;
		cn++;
		if(cn==n-1) return;
	}
}
long long kru(long long sum,long long tot,long long rp){
	long long cn=0;
	for(int i=1;i<=rp;i++){
		long long u=op[i].u,v=op[i].v;
		if(find(u)==find(v)) continue;
		un(u,v);
		sum+=op[i].w;
		cn++;
		if(cn==tot-1) return sum;
	}
}
bool vis[15];
void solve(){
	for(int i=1;i<=idx;i++) op[i]=fp[i];
	long long id=idx,res=0;
	for(int i=1;i<=n+k;i++) f[i]=i;
	int tot=n;
	for(int i=1;i<=k;i++){
		if(vis[i]){
			tot++,res+=c[i];
			for(int j=1;j<=n;j++){
				++id;
				op[id].u=n+i,op[id].v=j,op[id].w=a[i][j];
			}
		}
	}
	sort(op+1,op+id+1);
	ans=min(ans,kru(res,tot,id));
}
void dfs(int x){
	if(x>k){
		solve();
		return;
	}
	vis[x]=1,dfs(x+1);
	vis[x]=0,dfs(x+1);
}
bool flag=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++) cin>>op[i].u>>op[i].v>>op[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]) flag=1;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]) flag=1;
		}
	}
	sort(op+1,op+m+1);
	kruskal();
	for(int i=1;i<=m;i++) if(sav[i]) fp[++idx]=op[i];
	if(!flag){cout<<0;return 0;}
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
