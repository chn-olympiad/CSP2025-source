#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e4+4;
const int maxk = 14;
using ll = long long;
struct node{
	int u,v,w;
};
vector<node>edge;
int f[maxn],a[maxn];
bool cmp(node x,node y){
	return x.w<y.w;
}
int find(int x){
	return f[x]==x ? x : f[x]=find(f[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m,k; cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		edge.push_back((node){u,v,w});
	}
	for(int i=1;i<=k;i++){
		int c; cin>>c;
		for(int j=1;j<=n;j++)
			cin>>a[j];
	}
	for(int i=1;i<=n;i++) f[i]=i;
	sort(edge.begin(),edge.end(),cmp);
	ll ans=0ll; int cnt=0;
	for(auto ed:edge){
		int u=find(ed.u),v=find(ed.v);
		if(u==v) continue;
		f[find(u)]=find(v);
		ans+=ed.w;
		cnt++;
		if(cnt==n-1) break;
	}
	cout<<ans<<"\n";
	return 0;
}
