#include <bits/stdc++.h>
const int N = 5e6+101;
using namespace std;
int n,m,k,fa[N];
map<int,bool>mp,mp1;
int find(int x){
	if(fa[x] == x)return x;
	return fa[x] = find(fa[x]);
}
struct Node{
	int u,v,w;	
}edge[N];
bool cmp(Node a,Node b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i = 0;i<=n+10;i++)fa[i] = i;
	for(int i = 1;i<=m;i++){
		int u,v,w;
		cin>>edge[i].u>>edge[i].v>>edge[i].w;
	}
	for(int i = 1;i<=k;i++){
		int x;
		cin>>x;
		edge[++m] = {0,n+i,x};
		for(int j = 1;j<=n;j++){
			int k;
			cin>>k;
			edge[++m] = {n+i,j,k}; 
		}
	}
	sort(edge+1,edge+1+m,cmp);
//	for(int i = 1;i<=m;i++){
//		cout<<edge[i].u<<" "<<edge[i].v<<" "<<edge[i].w<<"\n";
//	}
	int ans=  0;
	int cnt = n;
	for(int i = 1;i<=m;i++){
		int x = find(edge[i].u);
		int y = find(edge[i].v);
		if(edge[i].u > n){
			if(mp[edge[i].u] == 0){
				continue;
			} 
		}
		if(x==y)continue;
		cout<<edge[i].u <<" " <<edge[i].v<<" "<<edge[i].w<<"\n";
		
		if(cnt <= 0)break;
		fa[x] = y;
		ans += edge[i].w;
		if(edge[i].u == 0){
			mp[edge[i].v] = 1;
		}
		if(edge[i].u >= 1&&edge[i].u <= n&&mp1[edge[i].u] == 0){
			mp1[edge[i].u] = 1;
			cnt -- ;
		}
		if(edge[i].v >= 1&&edge[i].v <= n&&mp1[edge[i].v] == 0){
			mp1[edge[i].v] = 1;
			cnt -- ;
		}
	}
	cout<<ans;
	return 0;
}
