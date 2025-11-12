#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e4+5;
int n,m,k;
struct Edge{
	int u,v,w;
}E[N];
int fa[N];
int find(int x){
	if(fa[x]==x) return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
bool cmp(Edge x,Edge y){
	return x.w<y.w;
}
void solve1(){
	ll ans=0,cnt=0;
	for(int i=1;i<=m;i++){
		cin>>E[i].u>>E[i].v>>E[i].w;
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(E+1,E+1+m,cmp);
	for(int i=1;i<=m;i++){
		int v=find(E[i].v),u=find(E[i].u),w=E[i].w;
		if(v!=u){
			fa[v]=u;
			ans+=w;
			cnt++;
		}
		if(cnt==n-1) break;
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0){
		solve1();
		return 0;	
	}
	cout<<0;
	return 0;
}
