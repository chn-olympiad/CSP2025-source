#include<bits/stdc++.h>
using namespace std;
const int MAXN=1050,MAXM=1050100;
int n,m,k;
int vis[MAXM];
int cnt=0,head[MAXN],nxt[MAXM*2],c[20],dis[MAXN][MAXN];
queue<int> p;
struct tu{
	int u,v,val,x;
};
tu f[MAXM];
void add(int u,int v,int val,int x){
	cnt++;
	f[cnt].u=u; f[cnt].v=v; f[cnt].val=val; f[cnt].x=x;
	nxt[cnt]=head[u];
	head[u]=cnt;	
	dis[u][v]=val;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	int u,v,val,x=0;
	for(int i=1;i<=n;i++) head[i]=-1;
	for(int i=1;i<=m;i++){
		x++;
		scanf("%d%d%d",&u,&v,&val);
		add(u,v,val,x);
		add(v,u,val,x);
	}  
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			x++;
			scanf("%d",&val);
			add(n+i,j,val,x);
			add(j,n+i,val,x);
		}
	}
	int now;
	if(k==0){
		p.push(1);
		while(!p.empty()){
			now=p.front();
			p.pop();
			for(int i=head[now];i!=-1;i=nxt[i]){
			}
		}
	}
	return 0;
}

