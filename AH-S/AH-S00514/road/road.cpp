#include<bits/stdc++.h>
#define ll long long
#define PII pair<ll,int>
using namespace std;
ll read(){
	ll s=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*f;
}
void write(ll x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
const int N=7e3+10;
ll t,n,m,k,u,v,w;
ll g[N][N],g2[N][N],d[15][N],dis[N],ans;
bool vis[N];
priority_queue<PII,vector<PII>,greater<PII>>q;
ll find(){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,false,sizeof(vis));
	ll sum=0;
	dis[1]=0;
	q.push(make_pair(0,1));
	while(1){
		int u=q.top().second;
		q.pop();
		while(q.size()&&vis[u]){
			u=q.top().second;
			q.pop();
		}
		if(vis[u])break;
		vis[u]=true;
		sum+=dis[u];
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				dis[i]=min(dis[i],g2[u][i]);
				q.push(make_pair(dis[i],i));
			}
		}
	}
	return sum;
}
void dfs(int x,int sum){
	if(x==k+1){
		ans=min(ans,find()+sum);
		return;
	}
	dfs(x+1,sum);
	memcpy(g2,g,sizeof(g));
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			g2[i][j]=min(g2[i][j],d[x][i]+d[x][j]);
			g2[j][i]=g2[i][j];
		}
	}
	dfs(x+1,sum+d[x][0]);
}
int main(){
	memset(g,0x3f,sizeof(g));
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ans=0x3f3f3f3f3f3f3f3f;
	n=read(),m=read(),k=read();
	while(m--){
		u=read(),v=read(),w=read();
		g[u][v]=min(g[u][v],w);
		g[v][u]=min(g[v][u],w);
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			d[i][j]=read();
		}
	}
	memcpy(g2,g,sizeof(g));
	dfs(1,0);
	cout<<ans;
	puts("");
	return 0;
}
