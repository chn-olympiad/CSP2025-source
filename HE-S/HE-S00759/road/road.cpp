#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MN=3e6+15,MK=12,INF=1e18;
struct Edge{
	int u,v,w,use;
}e[MN];
int n,m,K,c[MN],a[MK][MN],etot;
bool flagA=1;

namespace Kruskal{
	int pre[MN];

	void initpre(){
		iota(pre+1,pre+1+n,1);
	}

	int root(int x){
		if(pre[x]==x) return pre[x];
		else return pre[x]=root(pre[x]);
	}

	bool cmp(Edge x,Edge y){
		return x.w<y.w;
	}

	int kru(){
		initpre();
		sort(e+1,e+1+etot,cmp);
		int ret=0;
		for(int i=1;i<=etot;i++){
			int ru=root(e[i].u),rv=root(e[i].v);
			if(ru==rv) continue;
			e[i].use=1;
			ret+=e[i].w;
			pre[ru]=rv;
		}
		return ret;
	}
}

namespace Sub1{

int work(int st){
	// cerr<<st<<':';
	etot=m;
	int ret=0;
	for(int i=0;i<K;i++){
		if((st>>i)&1){
			// cerr<<i+1<<' ';
			ret+=c[i+1];
			for(int j=1;j<=n;j++){
				e[++etot]={i+1,j,a[i+1][j]+c[i+1]};
			}
		}
	}
	int tmp=Kruskal::kru();
	return tmp+ret;
}

void solve(){
	int ans=INF;
	for(int i=0;i<(1<<K);i++){
		ans=min(ans,work(i));
	}
	cout<<ans<<'\n';
}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>K;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=K;i++){
		cin>>c[i];
		if(c[i]) flagA=0;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]) flagA=0;
		}
	}
	if(flagA){
		cout<<0<<'\n';
	}
	else Sub1::solve();
	return 0;
}