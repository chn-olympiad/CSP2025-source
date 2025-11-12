#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll=long long;
struct Edge{
	int u,v;
	ll w;
};
vector<Edge> e,mt;
int fa[10004],m;
ll cst[11][10004];
vector<ll> sct[11];
void init(int t){
	for(int i=1;i<=t;i++)fa[i]=i;
}
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y)return;
	fa[x]=y;
}
bool cmp1(Edge &x,Edge &y){
	return x.w<y.w;
}
ll kru(int n,bool flag){
	sort(e.begin(),e.end(),cmp1);
	ll ans=0;
	int cnt=1;
	for(Edge c:e){
		if(cnt==n)break;
		if(find(c.u)==find(c.v))continue;
		merge(c.u,c.v);
		cnt++;
		ans+=c.w;
		if(flag)mt.push_back({c.u,c.v,c.w});
	}
	return ans;
}
ll sol(int t,int k,int n){
	ll res=0;
	int tot=0;
	e.clear();
	for(Edge c:mt)e.push_back(c);
	for(int i=1;i<=k;i++){
		if(!((t>>(i-1))&1))continue;
		tot++;
		res+=cst[i][0];
		for(int j=1;j<=n;j++)e.push_back({n+tot,j,cst[i][j]});
	}
	init(n+tot);
	return kru(n+tot,false)+res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,k;
	cin>>n>>m>>k;
	init(n);
	for(int i=1;i<=m;i++){
		int u,v;
		ll w;
		cin>>u>>v>>w;
		e.push_back({u,v,w}); 
	}
	for(int i=1;i<=k;i++){
		cin>>cst[i][0];
		for(int j=1;j<=n;j++){
			cin>>cst[i][j];
		}
	}
	ll res=kru(n,true),ans=res;
	int t=(1<<k)-1;
	for(int i=1;i<=t;i++)ans=min(ans,sol(i,k,n));
	cout<<ans;
	return 0;
}
