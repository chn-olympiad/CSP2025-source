#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=1e6+5;
int n,m,k,ans=0,f[N],c[15],a[15][N];
struct node{
	int u,v,w;
}xx[M];
bool cmp(node t1,node t2){
	return t1.w<t2.w;
}
int find(int x){
	if(x==f[x])return x;
	else return f[x]=find(f[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++)cin>>xx[i].u>>xx[i].v>>xx[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	sort(xx+1,xx+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(n==1)break;
		int u=find(xx[i].u),v=find(xx[i].v);
		if(u==v)continue;
		f[u]=v;
		n--;
		ans+=xx[i].w;
	}
	cout<<ans;
	return 0;
} 
