#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N(1e4+5);
int n,m,k,u,v,w;
vector<int>G[N];
struct Edge{
	int u,v;
	ll w;
};
// F1
int f[N];
int find(int x){
	if(x==f[x])return x;
	return f[x]=find(f[x]);
}
bool cmp1(Edge a,Edge b){
	return a.w<b.w;
}
inline void f1(){
	Edge a[N];int cnt(0);ll ans(0);
	for(int i(1);i<=m;++i){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}sort(a+1,a+n+1,cmp1);
	for(int i(1);i<=n;++i)f[i]=i;
	for(int i(1);i<=m;++i){
		int u(a[i].u),v(a[i].v);ll w(a[i].w);
		u=find(u),v=find(v);
		if(u!=v){
			f[u]=v;
			ans+=w;
			++cnt;
			if(cnt==n-1)break;
		}
	}cout<<ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	f1();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
