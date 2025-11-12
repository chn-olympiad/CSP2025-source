#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e4+5, M=1e6+5, inf=0x3f3f3f3f;
struct Edge{int u,v;ll w;};
int n,m,k,f[N];
ll c[N], ans=1e16;
bool use[15];
vector<Edge> e;
bool cmp(Edge x,Edge y){return x.w<y.w;}
int fnd(int x){
	if(f[x]==x) return x;
	else return f[x]=fnd(f[x]);
}
void unn(int u,int v){
	int fu=fnd(u), fv=fnd(v);
	if(fu==fv) return;
	f[fu]=fv;
}
ll kl(ll cft,int num){//cft为选择的乡镇的费用,num为选用乡镇个数 
	for(int i=1;i<=n+k;i++) f[i]=i;
	int cnt=0, mx=n+num-1;
	ll sum=cft;
	for(int i=0;i<e.size();i++){
		if(cnt==mx) break;
		int u=e[i].u, v=e[i].v;
		ll w=e[i].w;
		if(fnd(u)==fnd(v)) continue;//已联通 
		if(u>n && !use[u]) continue;//u镇不用 
		if(v>n && !use[v]) continue;//v镇不用 
		unn(u,v), sum+=w, cnt++;
		//if(cft==1) printf("connect %d & %d, NOW sum=%d\n",u,v,sum);
	}
	//printf("cft=%d sum=%d\n",cft,sum);
	return sum;
}
void dfs(int d,ll cft,int num){
	if(d==k){
		ans=min(ans, kl(cft,num));
		return;
	}
	use[d+n+1]=true;
	dfs(d+1,cft+c[d+n+1],num+1);
	use[d+n+1]=false;
	dfs(d+1,cft,num);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v; ll w;
		cin>>u>>v>>w,
		e.push_back({u,v,w});
	}
	for(int i=n+1;i<=n+k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			ll w; cin>>w;
			e.push_back({i,j,w});
		}
	}
	sort(e.begin(), e.end(), cmp);
	dfs(0,0,0);
	//1.枚举用哪几个乡镇O(2^k)
	//2.并查集跑最小生成树
	cout<<ans<<"\n";
	return 0;
} 
