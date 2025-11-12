#include<bits/stdc++.h>

using namespace std;
const int N=1e4+50,M=4e6+50,K=12,inf=0x3f3f3f3f;

inline int read(){
	int x=0,f=1; char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-48; c=getchar();}
	return x*f;
}
int n,m,k,ans;
struct Edge{
	int to,nxt,w;
}e[M];
int head[N],cnt;
void adde(int u,int v,int w){
	e[++cnt]={v,head[u],w},head[u]=cnt;
}
int c[K],a[K][N],st[N];
struct Node{
	int id,dis;
	friend bool operator<(Node x,Node y){
		return x.dis>y.dis;
	} 
};
int bfs(){
	int res=0;
	priority_queue<Node> q;
	q.push({1,0});
	while(q.size()){
		Node p=q.top(); q.pop(); int u=p.id; 
		if(st[u]) continue;
		st[u]=1,res+=p.dis;
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].to;
			if(!st[v]) q.push({v,e[i].w}); 
		}
	}
	return res;
}
void solve(){
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
		adde(u,v,w),adde(v,u,w);
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++) a[i][j]=read();
	}
	if(k==0){
		ans=bfs();
	}else if(k!=0){
		int ok=1;
		for(int i=1;i<=k;i++) if(c[i]) ok=0;
		if(ok){
			for(int i=1;i<=k;i++){
				int u=n+i;
				for(int v=1;v<=n;v++)
					adde(u,v,a[i][v]),adde(v,u,a[i][v]);
			}
			ans=bfs();
		}else ans=bfs();
	}
	printf("%d",ans);
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int T=1;
	while(T--) solve();
	return 0;
}

