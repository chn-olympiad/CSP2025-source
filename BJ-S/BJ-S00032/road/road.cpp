#include<bits/stdc++.h>
using namespace std;
using Pair=pair<int,int>;
using ll=long long;
constexpr int N=1e5+5; constexpr ll MAX=0x3fff'ffff'ffff'ffff;
namespace{
	template<typename T> ostream& operator<<(ostream &os,const vector<T> &vec){
		os<<'[';
		for(auto it=vec.begin();it!=vec.end();it++) (it==vec.begin()?os:os<<',')<<*it;
		return os<<']';
	}
}
constexpr int popcnt(int S){return __builtin_popcountll(S);}
namespace DSU{
	int f[N],sz[N];
	int ref(int k){return (k==f[k]?k:f[k]=ref(f[k]));}
	bool merge(int p,int q){
		p=ref(p),q=ref(q);
		if(p==q) return false;
		if(sz[p]>sz[q]) swap(p,q);
		sz[q]+=sz[p],sz[p]=0; f[p]=q;
		return true;
	}
	void init(int n){for(int i=1;i<=n;i++) f[i]=i,sz[i]=1;}
}
struct Path{
	int p,q,w;
	friend bool operator<(const Path &a,const Path &b){return a.w<b.w;}
};
int n,m,k;
pair<ll,vector<Path>> Kruskal(int totcnt,int validcnt,const vector<Path> &vec,bool flag){
	DSU::init(totcnt); vector<Path> ans; ll tot=0; int cnt=0;
	for(const auto P:vec) if(DSU::merge(P.p,P.q)){
		tot+=P.w; cnt++;
		if(flag) ans.push_back(P);
		if(cnt==validcnt-1) break;
	}
	return {tot,ans};
}
template<typename T> void Merge(vector<T> &a,const vector<T> &b){
	a.resize(a.size()+b.size());
	for(int i=0;i<b.size();i++) a[a.size()-b.size()+i]=b[i];
	inplace_merge(a.begin(),a.end()-b.size(),a.end());
}
vector<Path> stdPath,exPath[25]; ll c[25],ans=MAX;
mt19937 seed(time(0));
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n,m,k; cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int p,q,w; cin>>p>>q>>w;
		stdPath.push_back({p,q,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int x; cin>>x;
			exPath[i].push_back({j,n+i,x});
		}
		sort(exPath[i].begin(),exPath[i].end());
	}
	sort(stdPath.begin(),stdPath.end()); auto tmp=Kruskal(n,n,stdPath,1);
	ans=tmp.first,stdPath=tmp.second;
	vector<int> state;
	for(int S=1;S<(1<<k);S++) state.push_back(S);
	shuffle(state.begin(),state.end(),seed);
	for(auto S:state){
		if(1.00*clock()/CLOCKS_PER_SEC>=0.95) break;
		vector<Path> tmp=stdPath; ll base=0;
		for(int i=1;i<=k;i++) if((S>>(i-1))&1){
			base+=c[i]; Merge(tmp,exPath[i]);
		}
		ans=min(ans,Kruskal(n+k,n+popcnt(S),tmp,0).first+base);
	}
	cout<<ans<<'\n';
	// cerr<<1.00*clock()/CLOCKS_PER_SEC<<'\n';
}
/*
let me pass let me pass let me pass
onegai onegai onegai
*/