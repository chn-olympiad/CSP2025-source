#include<bits/stdc++.h>
using namespace std;
int n,m,k,f[10015],t,a[101];
long long s;
struct node{
	int u,v,w;
};
bool cmp(node a,node b){
	return a.w>b.w;
}
int fnd(int x){
	if(x==f[x]) return x;
	else return f[x]=fnd(f[x]);
}
int b[10001][10001];
vector<node> e;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e.push_back({u,v,w});
	}
	for(int i=1;i<=n;i++)
		f[i]=i;
	sort(e.begin(),e.end(),cmp);
	for(int i=1;i<=m;i++){
		int fu=fnd(e[i].u),fv=fnd(e[i].v);
		if(fu!=fv){
			s+=e[i].w;
			f[fu]=fv;
			b[e[i].u][e[i].v]=e[i].w;
		}
	}
	cout<<s;
}
