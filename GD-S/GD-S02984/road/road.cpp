#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m,k;
struct Node{
	int u,v,w;
};
vector<Node>g;
int c[14];
int vi[15][10004];
bool cmp(Node x,Node y){
	return x.w<y.w;
}
int f[10005];
int find(int x){
	if(f[x]==x) return x;
	else return f[x]=find(f[x]);
} 
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g.push_back({u,v,w});
	}	
	if(k==0){
	sort(g.begin(),g.end(),cmp);
	for(int i=1;i<=n;i++)
		f[i]=i;
	int num=0,ans=0;
	for(int i=0;i<m;i++){
		int X=find(g[i].u),Y=find(g[i].v);
		if(X==Y) continue;
		f[X]=Y;
		num++;
		ans+=g[i].w;
		if(num==n-1) break;
	}
	cout<<ans;
	}
	else{
	
	}
	return 0;
}
/*
5 6 0
1 2 3
2 3 4
3 4 5
5 1 6
1 5 7
4 5 8
*/
