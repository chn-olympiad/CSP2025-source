#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
const int N=1e4+50;
int n,m,k,head[N<<1],nxt[N<<1],tot,to[N<<1],wi[N<<1],dis[N],ans,ret=INT_MAX;
bool vis[N];
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-'){f=-1;}ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48),ch=getchar();}
	return x*f;
}
void write(int x){
	if(x<0){putchar('-');x=-x;}
	if(x<10){putchar(x+48);}
	else{write(x/10),putchar(x%10+48);}
	return;
}
void add(int u,int v,int w){
	nxt[++tot]=head[u];
	head[u]=tot;
	to[tot]=v,wi[tot]=w;
	return;
}
void bfs(int s){
	for(int i=1;i<=n;i++){
		vis[i]=0,dis[i]=0;
	}
	priority_queue<pi,vector<pi >,greater<pi > >q;
	q.push({0,s});
	while(q.size()){
		int u=q.top().second;q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i],w=wi[i];
			if(!dis[v]){
				dis[v]=dis[u]+w;
				ans+=w;
				q.push(make_pair(dis[v],v));
			}
		}
	}
}
void prim(){
	ans=0;
	bfs(1);
	ret=min(ret,ans);
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1,u,v,w;i<=m;i++){
		u=read(),v=read(),w=read();
		add(u,v,w),add(v,u,w);
	}
	prim();
	write(ret);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
