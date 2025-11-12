#include<bits/stdc++.h>
#define int long long
using namespace std;
int p;
const int N=2e4+10,M=1e6+10;//¼ì²éÄÚ´æ
struct node{
	int uuu,vvv,www;
}e[2*M],g[2*M];
int w[N],a[20][N]; 
int fa[N];
int n,m,k;
int uu[N],vv[N],ww[N];
bool cmp(node a,node b){
	return a.www<b.www;
}
int find(int x){
	if(x!=fa[x])fa[x]=find(fa[x]);
	return fa[x];
}
int kruskal(){
	int sum=0;
	sort(e+1,e+p+1,cmp);
	for(int i=0;i<=n+k;i++)fa[i]=i;
	for(int i=1;i<=p;i++){
		int a=find(e[i].uuu),b=find(e[i].vvv);
		if(a!=b){
			fa[a]=b;
			sum+=e[i].www;
		} 
	}
	return sum;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>uu[i]>>vv[i]>>ww[i];
		e[i]={uu[i],vv[i],ww[i]};
	}
	p=m;
	for(int i=1;i<=k;i++){
		cin>>w[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			e[++p]={n+i,j,a[i][j]};
		}
	}
    cout<<kruskal();
	return 0;
}
