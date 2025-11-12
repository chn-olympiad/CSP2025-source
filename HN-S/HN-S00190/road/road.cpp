#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define fi first
#define sc second
#define pii pair<int,int>
#define pdd pair<double,double>
#define pb push_back
#define umap unordered_map
#define mset multiset
#define pq priority_queue
#define ull unsigned long long
#define i128 __int128
#define FileIn(x) freopen(x".in","r",stdin)
#define FileOut(x) freopen(x".out","w",stdout)
#define FileIO(x) FileIn(x),FileOut(x)
const int maxn=1e4+20,maxm=1e6+10,maxk=10+10,maxs=(1<<10)+10;
struct Dsu{
	int f[maxn];
	void init(int n){
		for(int i=1;i<=n;i++) f[i]=i;
	}
	int find(int x){
		if(f[x]!=x) f[x]=find(f[x]);
		return f[x];
	}
	bool merge(int u,int v){
		int fu=find(u),fv=find(v);
		if(fu!=fv) return f[fu]=fv,1;
		return 0;
	}
}d;
struct Edge{
	int u,v,w;
}e[maxm];
int n,m,k,c[maxk][maxn],a[maxk];
ll sum[maxs];
bool flg[maxs];
vector<Edge> tmp,vec;
void solve(){
	cin>>n>>m>>k,d.init(n);
	for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=k;i++){
		cin>>a[i];
		for(int j=1;j<=n;j++) cin>>c[i][j];
	}
	sort(e+1,e+m+1,[](Edge x1,Edge x2){return x1.w<x2.w;});
	for(int i=1;i<=m;i++){
		if(d.merge(e[i].u,e[i].v)) tmp.pb(e[i]);
		if(tmp.size()==n-1) break;
	}
	ll res=2e18;
	for(int i=0;i<(1<<k);i++){
		vec=tmp,d.init(n+k);
		bool fl=0;
		ll minn=2e18;
		for(int j=(i-1)&i;j;j=(j-1)&i) fl|=flg[j],minn=min(minn,sum[j]);
		if(fl) continue;
		for(int j=1;j<=k;j++){
			if(!((i>>(j-1))&1)) continue;
			for(int l=1;l<=n;l++) vec.pb({j+n,l,c[j][l]});
			sum[i]+=a[j];
		}
		sort(vec.begin(),vec.end(),[](Edge x1,Edge x2){return x1.w<x2.w;});
		for(auto eg:vec) if(d.merge(eg.u,eg.v)) sum[i]+=eg.w;
		res=min(res,sum[i]);
//		cout<<i<<" "<<sum[i]<<endl;
		if(sum[i]>=minn) flg[i]=1;
//		cout<<i<<" "<<sum<<endl;
	}
	cout<<res<<endl;
}
int main(){
	FileIO("road");
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
//	cin>>t;
	while(t--) solve();
	return 0;
}

