#include<bits/stdc++.h>
#define ll long long
#define cin std::cin
#define cout std::cout
#define IOS cin.tie(nullptr)->sync_with_stdio(false);
const int N=2e4+5;
int n,m,k;
struct node{
	int v,next,w;
	bool operator < (const node& it)const{
		return it.w>w;
	}
};
node G[N];
int head[N],cnt;
void add(int u,int v,int w){
	G[++cnt].next=head[u];
	G[cnt].v=v;
	G[cnt].w=w;
	head[u]=cnt;
}
int fa[N];
int find(int x){
	if(x!=fa[x]) return find(fa[x]);
	return x;
}
int ans;
int val[N];
int c[N][N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
		ans+=w;
	}
	for(int i=1;i<=k;i++){
		cin>>val[i];
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
		}
	}
	cout<<ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
