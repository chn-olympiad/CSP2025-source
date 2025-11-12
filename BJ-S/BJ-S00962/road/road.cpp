#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int n,m,k;
struct edge{
	int u,v,w;
}e[N];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int fa[N],tmp[N];
void init(){
	for(int i=1;i<=n;i++) fa[i]=i;
}
int find(int x){
	if(fa[x]!=x) return fa[x]=find(fa[x]);
	return fa[x];
}
long long kruskal(){
	init();
	sort(e+1,e+m+1,cmp);
	long long res=0,cnt=0;
	for(int i=1;i<=m;i++){
		int u=find(e[i].u),v=find(e[i].v);
		if(u!=v){
			fa[u]=v,res+=e[i].w,cnt++;
			if(cnt==n-1) break;
		}
	}
	return res;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	if(k==0){
		cout<<kruskal();
		return 0;
	}
	for(int i=1;i<=k;i++){
		int c,pos=0;
		cin>>c;
		for(int j=1;j<=n;j++){
			cin>>tmp[j];
			if(tmp[j]==0) pos=j;
		}
		for(int j=1;j<=n;j++){
			if(j!=pos) e[++m]=edge{pos,j,tmp[j]};
		}
	}
	cout<<kruskal();
	return 0;
}
