#include<bits/stdc++.h>
using namespace std;
int n,m,k,c,a,p[10002];
struct node{int u,v,w;};
bool cmp(node x,node y){
	return x.w<y.w;
}
vector<node>g;
long long sum;
int Find(int x){
	if(p[x]==x)return x;
	else return p[x]=Find(p[x]);
}
int main(){
	ios::sync_with_stdio(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k>0)return 0;
	for(int i=0;i<m;i++){
		int U,V,W;
		cin>>U>>V>>W;
		g.push_back({U,V,W});
	}sort(g.begin(),g.end(),cmp);
	for(int i=1;i<=n;i++)p[i]=i;
	for(int i=0;i<m;i++){
		int pu=Find(g[i].u),pv=Find(g[i].v);
		if(pu!=pv){
			p[pu]=pv;
			sum+=(g[i].w*1ll);
		}
	}cout<<sum;
	return 0;
}
