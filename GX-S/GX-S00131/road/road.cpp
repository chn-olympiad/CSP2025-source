#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1e4+10,M=1e6+10,K=20,inf=1e18;
int n,m,k,cnt,Ans=inf,u[M],v[M],w[M],fa[N],c[K],a[K][N];
struct node{
	int u,v,w;
}e[M<<1];
int read(){
	int x=0;char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c&15),c=getchar();
	return x;
}
bool cmp(node x,node y){
	return x.w<y.w;
}
int find(int x){
	while(x!=fa[x]) x=fa[x]=fa[fa[x]];
	return x;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++) u[i]=read(),v[i]=read(),w[i]=read();
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++) a[i][j]=read();
	}
	for(int t=0,ans=0,tot=m,x=0;t<=(1<<k)-1;t++,ans=0,tot=m,x=0){
		memset(e,0,sizeof(e));
		for(int i=1;i<=m;i++) e[i]=(node){u[i],v[i],w[i]};
		for(int i=1;i<=n+k;i++) fa[i]=i;
		for(int i=1;i<=k;i++){
			if(t>>(i-1)&1){
				ans+=c[i],x++;
				for(int j=1;j<=n;j++) e[++tot]=(node){n+i,j,a[i][j]};
			}
		}
		//cout<<tot<<'\n';
		sort(e+1,e+tot+1,cmp);
		for(int i=1,u,v,cnt=n+x-1;cnt;i++){
			u=find(e[i].u),v=find(e[i].v);
			if(u!=v) ans+=e[i].w,fa[u]=v,cnt--/*,cout<<e[i].u<<' '<<e[i].v<<' '<<e[i].w<<'\n'*/;
			if(ans>Ans) break;
		}
		//cout<<t<<' '<<ans<<endl;
		Ans=min(ans,Ans);
	}
	printf("%lld",Ans);
}
