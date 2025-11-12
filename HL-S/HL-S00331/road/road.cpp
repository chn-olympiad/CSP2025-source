#include<bits/stdc++.h>
#define int long long
using namespace std;

struct node{
	int v,w;
};
struct eage{
	int id,u,v,w;
};
int n,m,k,ans;
bool f[10010];
vector<node > a[100010];
eage e[100010];
bool cmp(eage x,eage y){
	return x.w<y.w;
}
bool check(){
	for(int i=1;i<=n;i++){
		if(!f[i])return 0;
	}
	return 1;
}
bool check1(eage x){
	return 1;
}
void sxs(){
	sort(e+1,e+m+1,cmp);
	for(int i=0;i<m&&!check();i++){
		if(check1(e[i])){
			f[e[i].u]=1;
			f[e[i].v]=1;
			ans+=e[i].w;
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[u].push_back({v,w});
		a[v].push_back({u,w});
		e[i].id=i,e[i].u=u,e[i].w=w,e[i].v=v;
	}
	return 0;
}

