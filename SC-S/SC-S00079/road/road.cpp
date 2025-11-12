#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,cn,re,fa[500001];
struct E{
	int u,v,w;
}e[2000001];
bool cmp(E x,E y){
	return x.w<y.w;
}
int fi(int x){
	return (x==fa[x]?x:fa[x]=fi(fa[x]));
}
void un(int x,int y){
	x=fi(x),y=fi(y);
	fa[x]=y;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m>>k,cn=m;
	for(int i=1;i<=m;i++)
		cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=k;i++){
		int c;cin>>c;
		for(int j=1;j<=n;j++){
			int x;cin>>x;
			e[++cn]={i+n,j,x};
		}
	}
	for(int i=1;i<=n+k;i++)fa[i]=i;
	sort(e+1,e+cn+1,cmp);
	for(int i=1;i<=cn;i++){
		int u=e[i].u,v=e[i].v;
		if(fi(u)==fi(v))continue;
		un(u,v),re+=e[i].w;
	}
	cout<<re;
	return 0;
}