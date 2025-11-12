#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int fg=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') fg=-fg;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return fg*x;
}
int n,m,k,cnt,head[2000001],c[20],a[11][10001],f[10001],ans=-1;
bool vis[10001];
struct node{
	int to,next,val;
}e[2000001];
struct pp{
	int num,pos;
	const bool operator < (const pp &x)const{
		return pos<x.pos;
	}
};
priority_queue<pp> q;
void add(int u,int v,int w){
	cnt++;
	e[cnt].to=v;
	e[cnt].val=w;
	e[cnt].next=head[u];
	head[u]=cnt;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=1,u,v,w;i<=m;i++){
		u=read();v=read();w=read();
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++) a[i][j]=read();
	}
	memset(f,0x3f,sizeof(f));
	f[1]=0;
	q.push((pp){1,0});
	while(!q.empty()){
		int u=q.top().num;
		q.pop();
		if(vis[u]) continue;
		vis[u]=true;
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].to;
			if(vis[v]) continue ;
			if(f[v]>f[u]+e[i].val){
				f[v]=f[u]+e[i].val;
				q.push((pp){v,f[v]});
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k;j++){
				if(i!=u&&!vis[i]){
					if(f[i]>f[u]+a[j][u]+a[j][i]){
						f[i]=f[u]+a[j][u]+a[j][i];
						q.push((pp){i,f[i]}); 
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,f[i]);
	}
	printf("%lld",ans);
	return 0;
}
