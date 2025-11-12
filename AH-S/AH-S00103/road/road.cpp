#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,c[15],ks[10005],maxn,rt;
long long a[15][10005],mins=0,cs=1e18,minn=1e18;
struct node{
	int u,v,p;
	long long w;
}e[20005];
int h[10005],ecnt;
void add(int u,int v,int w){
	e[++ecnt].p=h[u];
	h[u]=ecnt;
	e[ecnt].u=u,e[ecnt].v=v,e[ecnt].w=w;
}
bool vis[10005];
long long ans,anss;
void dfs(int u,long long s){
	if(u==rt){
		anss=s;
		return;
	}
	for(int i=h[u];i;i=e[i].p){
		int j=e[i].v;
		if(vis[j])continue;
		if(j==rt)dfs(j,s);
		else{
			vis[j]=1;
			dfs(j,s+e[i].w);
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
		mins+=w,ks[u]++,ks[v]++;
		if(ks[u]>maxn)maxn=ks[u],rt=u;
		if(ks[v]>maxn)maxn=ks[v],rt=v;
	}
	if(k==0){
		long long maxans=0;
		for(int i=h[rt];i;i=e[i].p){
			int j=e[i].v;
			if(e[i].u==rt)maxans+=e[i].w;
			else continue;
			if(!vis[j]){
				vis[j]=1;
				dfs(j,e[i].w);
				ans+=anss;
			}
		}
		cout<<min(mins,min(ans,maxans));
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		bool flag=1;
		if(c[i])flag=0;
		long long sa=c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j])flag=0;
			sa+=a[i][j];
		}
		cs=min(cs,sa);
		if(flag){
			cout<<"0";
			return 0;
		}
		cout<<min(mins,cs);
	}
	return 0;
}
