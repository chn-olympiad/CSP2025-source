#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+5;
int n,m,k;
ll c[15],a[15][N];
struct str{int u,v,w;};
vector<str> E;
vector<pair<int,int>> e[N];
bool cmp(str x,str y){
	return x.w<y.w;
}
int fa[N];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		E.push_back({u,v,w});
	}
	ll fff=LLONG_MAX;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		bool f=1;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]!=0) f=0;
		}
		if(f) fff=min(fff,c[i]);
	}
	if(k>0 && fff==0){
		cout<<0;
		return 0;
	}
	int cnt=0;
	sort(E.begin(),E.end(),cmp);
	ll s=0; 
	for(auto t:E){
		int u=t.u,v=t.v,w=t.w;
		int t1=find(u),t2=find(v);
		if(t1!=t2){
			fa[t1]=t2;
			e[u].push_back({v,w});
			e[v].push_back({u,w});
			cnt++;
			s+=w;
		}
		if(cnt==n-1) break;
	}
	int rt=find(1);
	cout<<min(s,fff);
	return 0;
} 
