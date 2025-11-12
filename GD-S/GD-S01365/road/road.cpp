#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int M=2e6+10;
int n,m,k,c[20][2],a[20][1050],pa[1050],tmpm,tmpn;
ll cur;
ll all;
struct Edge{
	ll u,v,w;
}e[M],tmp[M];
bool cmp(Edge a,Edge b){
	return a.w<b.w;
}
void init(){
	for(int i=1;i<=n;i++)pa[i]=i;
}
int find(int x){
	return pa[x]==x?x:pa[x]=find(pa[x]);
}
void merge(int x,int y){
	pa[find(y)]=find(pa[x]);
}
int kruskal(){
	ll ans=0,sum=0;
	for(int i=1;i<=m;i++){
		Edge now=e[i];
		if(find(e[i].u)!=find(e[i].v)){
			sum++;
			ans+=e[i].w;
			merge(e[i].u,e[i].v);
		}
		if(sum==n-1)break;
	}
	return ans;
}
void copy(bool where){
	if(where==1){
		for(int i=1;i<=m;i++){
			tmp[i]=e[i];
			tmpm=m;
			tmpn=n;
		}
	}else{
		for(int i=1;i<=tmpm;i++){
			e[i]=tmp[i];
		}
		m=tmpm;
		n=tmpn;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i][1];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	stable_sort(e+1,e+m+1,cmp);
	init();
	all=kruskal();
	for(int i=1;i<=k;i++){
		copy(1);
		cur+=c[i][1];
		ll sum=cur;++n;
		for(int j=1;j<=n;j++){
			e[++m]={n,j,a[i][j]};
		}
		stable_sort(e+1,e+m+1,cmp);
		init();
		sum+=kruskal();
		if(all<=sum){
			copy(0);
			cur-=c[i][1];
		}else{
			all=sum;
		}
	}
	cout<<all;
	return 0;
}

