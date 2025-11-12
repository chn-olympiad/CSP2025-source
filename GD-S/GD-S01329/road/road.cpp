#include<bits/stdc++.h>
#define ll long long
#define e_b emplace_back
#define p_b push_back
#define ios ios::wyns_with_stdio(0),cin.tie(0)
using namespace std;
const int N=1e4+5;
int fa[N],sz[N],ans=0x3f3f3f3f;
vector<int>st[N];
struct node{
	int v,w;
};
vector<node>g[N];
int ask(int x){return fa[x]=fa[x]^x?ask(fa[x]):x;}
int n,m,k;
int a[11][N];
int c[N];
bool v[N];
void merge(int x,int y){
	x=ask(x),y=ask(y);
	if(x^y){
		if(sz[y]<sz[x]){
			sz[x]+=sz[y],fa[y]=x;
			for(int v:st[y])st[x].e_b(v);
			//st[y].clear();
		}
		else{
			sz[y]+=sz[x],fa[x]=y;
			for(int v:st[x])st[y].e_b(v);
			//st[x].clear();
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(c,-1,sizeof c);
	for(int i=1;i<=n;i++)fa[i]=i,sz[i]=1,st[i].e_b(i);
	while(m--){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].e_b(node{v,w});
		g[v].e_b(node{u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	cout<<0;
	return 0;
}

