#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;

int n,m,k;
struct node{
	int u,v,w;
}edge[1200005];
int rp;
bool cmp(node a,node b){
	return a.w<b.w;
}
int fa[1200005];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x] = find(fa[x]);
} 
void unionn(int x,int y){
	x = find(x),y = find(y);
}
void solveA(){
	for(int i = 1;i<=m;i++){
		cin>>edge[i].u>>edge[i].v>>edge[i].w;
	}
	sort(edge+1,edge+1+m,cmp);
	for(int i = 1;i<=n;i++) fa[i] = i;
	int ans = 0;
	int cnt = 0;
	for(int i = 1;i<=m&&cnt<n-1;i++){
		int tx = find(edge[i].u);
		int ty = find(edge[i].v);
		if(tx==ty) continue;
		cnt++;
		ans+=edge[i].w;
		unionn(tx,ty); 
	} 
	cout<<ans;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	if(k==0){
		solveA();
		return 0;
	}
//	cout<<0;
	for(int i = 1;i<=m;i++){
		cin>>edge[i].u>>edge[i].v>>edge[i].w;
		++rp;
	} 
	for(int i = 1;i<=k;i++){
		int TMP;
		cin>>TMP;
		for(int i = 1;i<=n;i++){
			int x;
			cin>>x;
			edge[++rp].u = i;
			edge[rp].v = n+1;
			edge[rp].w = x;
		} 
	}
	sort(edge+1,edge+1+rp,cmp);
	for(int i = 1;i<=n+1;i++){
		fa[i] = i;
	}
	int ans = 0;
	int cnt = 0;
	for(int i = 1;i<=m&&cnt<n-1;i++){
		int tx = find(edge[i].u);
		int ty = find(edge[i].v);
		if(tx==ty) continue;
		if(edge[i].u!=n+1&&edge[i].v!=n+1) cnt++;
		ans+=edge[i].w;
		unionn(tx,ty); 
	} 
	cout<<ans;
	return 0;
}

