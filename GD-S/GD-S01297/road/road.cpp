#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e6+5,M = 11;

struct node{
	int u,v;
	ll w; 
	bool operator<(node b)const{
		return w<b.w;
	}
}E[N];
unordered_map<int,node> cur[1<<M];

struct Node{
	ll w;
	int id;
	bool operator<(Node b)const{
		return w<b.w;
	}
}a[M][N];
int tot;
int n,m,k;
int fa[N];
ll W[M];
int siz[N];
ll ans;

int find_root(int u){
	return (fa[u]==u ? fa[u] : fa[u]=find_root(fa[u]));
}
void dfs(int u,ll cs,int cr){
	if(u>k)return ;
	int pre=tot;
	dfs(u+1,cs,cr);
	
	for(int i=1;i<=n+k;i++)
		fa[i]=i,siz[i]=1;
	tot=0;
	int nxt=cr+(1<<u-1);
	int pos1=1,pos2=1;
	for(int i=1;i<=pre+n;i++){
		if(pos1<=pre && cur[cr][pos1].w<a[u][pos2].w || pos2>n)cur[nxt][++tot]=cur[cr][pos1++];
		else cur[nxt][++tot]=(node){u+n,a[u][pos2].id,a[u][pos2].w},pos2++;
	}
//	cout<<tot<<"\n";
//	for(int i=1;i<=pre+n;i++)
//		cout<<cur[nxt][i].u<<" "<<cur[nxt][i].v<<" "<<cur[nxt][i].w<<"\n";
	ll res=cs+W[u];
	int p=0;
	for(int i=1;i<=tot;i++){
		int fx=find_root(cur[nxt][i].u),fy=find_root(cur[nxt][i].v);
		if(fx!=fy){
			if(siz[fx]<siz[fy])swap(fx,fy);
			fa[fy]=fx,res+=cur[nxt][i].w,siz[fx]+=siz[fy];
			cur[nxt][++p]=cur[nxt][i];
		}
	}
//	cout<<cs+W[u]<<" "<<res<<"\n";
	tot=p;
	ans=min(ans,res);
	dfs(u+1,cs+W[u],nxt);
	tot=pre;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin>>n>>m>>k;
	
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
		cin>>E[i].u>>E[i].v>>E[i].w;
	
	sort(E+1,E+m+1);
	
	for(int i=1;i<=m;i++){
		int fx=find_root(E[i].u),fy=find_root(E[i].v);
		if(fx!=fy){
			if(siz[fx]<siz[fy])swap(fx,fy);
			fa[fy]=fx,ans+=E[i].w,siz[fx]+=siz[fy],cur[0][++tot]=E[i];
		}
	}
	
	for(int i=1;i<=k;i++){
		cin>>W[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j].w,a[i][j].id=j;
		sort(a[i]+1,a[i]+n+1);
	}
	
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
/*
4 4 2
1 4 0
2 3 7
4 2 0
4 3 4
0 1 0 2 4
0 2 3 2 0
*/
