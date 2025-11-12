#include<bits/stdc++.h>
using namespace std;
int n,m,k,f[10011],sum;
struct Edge{
	int u,v,w;
}e[1000001+100001];
int find(int x){
	if(f[x]==x){
		return f[x];
	}
	return find(f[x]);
}
bool cmp(Edge x,Edge y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	int nn=n;
	for(int i=1;i<=n+k;i++){
		f[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=k;i++){
		int tmp;
		cin>>tmp;
		for(int j=1;j<=nn;j++){
			int ww;
			cin>>ww;
			e[++m].u=++n,e[m].v=j,e[m].w=ww;
		}
	}
	stable_sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++){
		int a=find(e[i].u),b=find(e[i].v);
		if(a!=b){
			f[a]=b;
			sum+=e[i].w;
		}
	}
	cout<<sum;
	return 0;
}
