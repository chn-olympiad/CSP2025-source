#include<bits/stdc++.h>
using namespace std;

long long ans=LONG_LONG_MAX,sum,summ=0;
int n,m,tot=0,head[10020],qi[3000005],to[3000005],nex[3000005],W[3000005],vis[10020],k,a[15],dis[15][10005];
bool book[10020];

void add(int x,int y,int z){
	nex[++tot]=head[x];
	to[tot]=y;
	qi[tot]=x;
	head[x]=tot;
	W[tot]=z;
	return;
}

void qingkong(){
	head[qi[tot]]=nex[tot];
	tot--;
	return;
}

void min_tree(int x,int y){
	book[x]=true;
	for(int i=head[x];i!=0;i=nex[i])
		vis[to[i]]=min(vis[to[i]],W[i]);
	int minn=0;
	for(int i=1;i<=y;i++)
		if(!book[i] && vis[i]<vis[minn])
			minn=i;
	if(minn!=0){
		sum+=vis[minn];
		min_tree(minn,y);
	}
	return;
}

void dfs(int x,int y){
	if(x==k+1){
		for(int i=2;i<=y;i++){
			book[i]=false;
			vis[i]=INT_MAX;
		}	
		sum=summ;
		min_tree(1,y);
		ans=min(ans,sum);
		return;
	}
	dfs(x+1,y);
	summ+=a[x];
	y++;
	for(int i=1;i<=n;i++){
		add(i,y,dis[x][i]);
		add(y,i,dis[x][i]);
	}
	dfs(x+1,y);
	y--;
	for(int i=1;i<=2*n;i++)
		qingkong();
	summ-=a[x];
	return;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>n>>m>>k;
	int u,v,w;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=k;i++){
		cin>>a[i];
		for(int j=1;j<=n;j++)
			cin>>dis[i][j];
	}
	vis[0]=INT_MAX;
	dfs(1,n);
	cout<<ans;
	return 0;
} 
