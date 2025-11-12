#include<bits/stdc++.h>
using namespace std;
struct edge{
	int u,v;
	int w;
}e[1000010];
int size=0,f[10100],ans=0,n,m,k;
bool cmp(edge x,edge y){
	return x.w<y.w;
}
bool check(int x){
	int u=e[x].u,v=e[x].v;
	if(f[u]==f[v])return 0;
	for(int i=1;i<=n;i++)if(f[i]==f[u])f[i]=f[v];
	return 1;
}
void Kru(){
	for(int i=1,j=1;i<=size&&j<=n-1;i++)
		if(check(i))ans+=e[i].w,j++;
	cout<<ans;
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		size++;
		e[size].u=u;
		e[size].v=v;
		e[size].w=w;
	}
	sort(e+1,e+1+size,cmp);
	for(int i=1;i<=n;i++)f[i]=i;
	Kru();
	return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4

*/
