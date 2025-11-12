#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
struct node{
	int u,v;
	long long w;
	bool operator < (const node &x) const {
		return w<x.w;
	}
}e[N];
int n,m,k;
long long ans,co[11];
int fa[N];
vector<long long>costt[11];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	fa[find(x)]=find(y);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;cin>>u>>v>>w;
		e[i]={u,v,w};
	}
	for(int i=1;i<=k;i++){
		cin>>co[i];
		for(int j=1;j<=n;j++){
			int w;cin>>w;
			e[++m]={i+n,j,w+co[i]};
		}
	}
	for(int i=1;i<=n+k;i++) fa[i]=i;
	sort(e+1,e+m+1);
	for(int i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v;
		long long w=e[i].w;
		if(find(u)==find(v)) continue;
		ans+=w;
		merge(u,v);
		if(u>n){
			if(costt[u-n].size()==0){
				for(int j=1;j<=m;j++) if(e[j].u==u) e[j].w-=co[u-n];
				sort(e+1,e+m+1);i=0;
			}
			costt[u-n].push_back(w);
		}
	}
	for(int i=1;i<=k;i++){
		if(costt[i].size()==1){
			ans-=costt[i][0];
		}
	}
	cout<<ans;
	return 0;
}
