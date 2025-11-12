#include<bits/stdc++.h>
using namespace std;
const int N=1105,M=2000005;
int n,m,k;
int c[15],a[15][N];
struct Edge{
	int u,v,w;
}e[M],E[M];
bool cmp(Edge x,Edge y){
	return x.w<y.w;
}
int fa[N];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
long long solve1(){
	sort(e+1,e+m+1,cmp);
	long long ans=0;
	for(int i=1;i<=n;i++){fa[i]=i;}
	for(int i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(find(u)!=find(v)){
			fa[fa[u]]=fa[v];
			ans+=w;
		}
	}
	return ans;
}
void solve2(){
	int M=0;
	sort(e+1,e+m+1,cmp);
	long long ans=0;
	int lst=0;
	for(int i=1;i<=n;i++){fa[i]=i;}
	for(int i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(find(u)!=find(v)){
			fa[fa[u]]=fa[v];
			ans+=w;
			lst=w;
		}
		if(lst==w){
			E[++M]=e[i];
		}
	}

	int N=n;
	long long maxans=ans;
	for(int S=1;S<(1<<k);S++){
		m=M;n=N;
		for(int i=1;i<=m;i++){
			e[i]=E[i];
		}
		for(int i=1;i<=k;i++){
			if(!(i&S))continue;
			for(int j=1;j<=n;j++){
				E[++m]={n+i,j,a[i][j]};
			}
		}
		n+=k;
		maxans=min(maxans,solve1());
	}
	cout<<maxans;
}
void solve3(){
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			e[++m]={j,n+i,a[i][j]};
		}
	}
	n+=k;
	cout<<solve1();
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(k==0){
		cout<<solve1();
	}else if(k<=5){
		solve2();
	}else{
		solve3();
	}
	return 0;
}