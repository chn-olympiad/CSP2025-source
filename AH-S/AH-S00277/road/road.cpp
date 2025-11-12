#include<bits/stdc++.h>
#define int long long
#define ll long long
#define pii pair<int,int>
#define ALL(x) x.begin(),x.end()
using namespace std;
const int MOD1=1e9+7,MOD2=998244353;
const int MOD=MOD1;
const int INF=1e18;
const int N=10015,M=1000005;
int n,m,k;
struct DSU{
	int fa[N];
	int find(int x){
		return (x==fa[x]?x:fa[x]=find(fa[x]));
	}
	void unite(int x,int y){
		int fax=find(x),fay=find(y);
		if(fax!=fay){
			fa[fax]=fay;
		}
	}
}dsu;
struct Edge{
	int u,v,w;
};
vector<Edge> E1,E2,E3,tmp;
int a[15][N],c[15];
int calc(){
	for(int i=1;i<=n+k;i++){
		dsu.fa[i]=i;
	}
	tmp=E3;
	sort(ALL(tmp),[](Edge x,Edge y){return x.w<y.w;});
	int res=0;
	for(auto [u,v,w]:tmp){
		if(dsu.find(u)!=dsu.find(v)){
			dsu.unite(u,v);
			res+=w;
		}
	}
	return res;
}
void solve_(){
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		E1.push_back({u,v,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		dsu.fa[i]=i;
	}
	sort(ALL(E1),[](Edge x,Edge y){return x.w<y.w;});
	for(auto [u,v,w]:E1){
		if(dsu.find(u)!=dsu.find(v)){
			dsu.unite(u,v);
			E2.push_back({u,v,w});
		}
	}
	E3=E2;
	int ans=INF;
	for(int i=0;i<(1<<k);i++){
		int s=0;
		for(int j=1;j<=k;j++){
			if((i>>(j-1))&1){
				s+=c[j];
				for(int u=1;u<=n;u++){
					E3.push_back({u,n+j,a[j][u]});
				}
			}
		}
		ans=min(ans,s+calc());
		while(E3.size()>=n)E3.pop_back();
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int testcase=1,multitest=0;
	if(multitest)cin>>testcase;
	while(testcase--){
		solve_();
	}
	return 0;
}
