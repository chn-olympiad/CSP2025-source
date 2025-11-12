#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=2e6+5;
int n,m,k,f[N],ans;
int find(int x){
	return x==f[x]?x:f[x]=find(f[x]);
}
struct edge{
	int x,y,w;
}e[M];
bool cmp(edge a,edge b){
	return a.w<b.w;
}
void calc(int x,int y,int w){
	x=find(x),y=find(y);
	if(x!=y){
		ans+=w;
		f[x]=y;
	}
}
void kruskal(){
	for(int i=1;i<=n;i++)f[i]=i;
	
	for(int i=1;i<=k;i++)
	for(int j=1;j<=n;j++)calc(i,j,0);
	
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=m;i++)calc(e[i].x,e[i].y,e[i].w);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		scanf("%d %d %d ",&e[i].x,&e[i].y,&e[i].w);
	kruskal();
	cout<<ans;
}