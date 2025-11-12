#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
struct node{
	int cost,a,b;
};
node road[50000005];
int vis[10005],c[10005],a[20][10005];
bool cmp(node x,node y){
	return x.cost<y.cost;
}
int fa[10005];
void init(){
	for(register int i=1;i<=n;i++) fa[i]=i;
}
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void un(int x,int y){
	fa[x]=find(fa[y]);
}
int kruskal(){
	init();
	sort(road+1,road+1+m,cmp);
	int cnt=0,buildcost=0;
	for(register int i=1;i<=m;i++){
		if(find(road[i].a)==find(road[i].b)){
			continue;
		}
		un(road[i].a,road[i].b);
		cnt++;
		buildcost+=road[i].cost;
		if(cnt==n-1){
			break;
		}
	}
	return buildcost;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	int nn=n;
	for(register int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		road[i].cost=c,road[i].a=a,road[i].b=b;
	}
	bool flag=1;
	for(register int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0) flag=0;
		for(register int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(k==0){//最小生成树 
		cout<<kruskal();
		return 0;
	}
	if(flag){
		for(register int lol=1;lol<=k;lol++){
			//if(c[lol]!=0) continue; 
			for(register int i=1;i<=nn;i++){
				++n;
				road[++m].cost=a[n][i];
				road[m].a=n,road[m].b=i;
			}
		}
		cout<<kruskal();
	}
	return 0;
}
/*

*/
/*
4 6 0
1 2 2
1 3 4
2 3 4
3 4 2
2 4 3
1 4 3
*/
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
0 1 8 2 4
0 1 3 2 4
*/
