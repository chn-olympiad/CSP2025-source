#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans;
const int N=1000005;
typedef struct Edge{
	int u;
	int v;
	int w;
}Edge ;
Edge edge[N];
int fa[N],cnt;
void un(int x,int y);
int find(int x);
void solve1();
void solve2();
bool cmp(const Edge e1,const Edge e2){
	return e1.w<e2.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=n;i++){
		fa[i]=i;
	}
	for (int i=1;i<=m;i++){
		cin>>edge[i].u>>edge[i].v>>edge[i].w;
	}
	if (k==0){
		solve1();
		return 0;
	}else{
		solve2();
		return 0;
	}
	return 0;
}
void solve1(){
	sort(edge+1,edge+1+m,cmp);
	for (int i=1;i<=m;i++){
		if (find(edge[i].u)==find(edge[i].v))continue;
		ans+=edge[i].w;
		un(edge[i].u,edge[i].v);
	}
	cout<<ans;
}
void solve2(){
	cout<<0;
}
void un(int x,int y){
	int nx=find(x);
	int ny=find(y);
	if (nx!=ny){
		fa[nx]=ny;
	}
	
}
int find(int x){
	return (fa[x]==x)?fa[x]:fa[x]=find(fa[x]);
}
