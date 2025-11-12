#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10,M=2e4+5,inf=1e14;
int n,m,k,head[M],idx,c[15],nn,mm,cntn;
int a[13][M];
struct edge{
	int u,v,w;
}edg[N<<1],g[N<<1],gx[M];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int read(){
	int z=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){
		z=z*10+c-'0';
		c=getchar();
	}
	return z;
}
int S,f[M],flag;
struct node{
	int len,u,v;
};
bool cmp1(node x,node y){
	return x.len<y.len;
}
vector<node> q[10];
int c1[10];
int find(int x){
	if(x==f[x])return x;
	return f[x]=find(f[x]);
}
void kruscal(){
	sort(edg+1,edg+mm+1,cmp);
	for(int i=1;i<=mm;i++){
		int u=edg[i].u,v=edg[i].v,w=edg[i].w;
		int fx=find(u),fy=find(v);
		if(fx!=fy) {
			S+=w;
			f[fx]=fy;
			nn--;
		}
		if(!nn)break;
	}
	printf("%lld",S);
}
int vis[11],sum,mn;
void kr(){
	sort(g+1,g+mn+1,cmp);
	for(int i=1;i<=n+k;i++){
		f[i]=i;
	}
	for(int i=1;i<=mn;i++){
		int u=g[i].u,v=g[i].v,w=g[i].w;
		int fx=find(u),fy=find(v);
		if(fx!=fy) {
			if(!flag)gx[++cntn]=g[i];
			sum+=w;
			f[fx]=fy;
		}
	}
	S=min(S,sum);
}
void dfs(int u){
	if(u>k){
		mn=cntn;
		sum=0;
		for(int i=1;i<=cntn;i++){
			g[i]=gx[i];
		}
		for(int i=1;i<=k;i++){
			if(!vis[i])continue;
			sum+=c[i];
			for(int u=1;u<=n;u++){
				g[++mn]={u,i+n,a[i][u]};
			}
		}
		if(sum>S)return;
		kr();
		return;
	}
	vis[u]=1;
	dfs(u+1);
	vis[u]=0;
	dfs(u+1);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
		edg[i]={u,v,w};
	}
	mm=m,nn=n;int cnt=0;
	for(int i=1;i<=k;i++){
		c[i]=read();
		nn++;int fl=0;
		for(int j=1;j<=n;j++){
			a[i][j]=read();
			if(a[i][j]==0)fl=1;
			edg[++mm]={nn,j,a[i][j]};
		}
		if(fl&&c[i]==0)cnt++;
	}
	for(int i=1;i<=nn;i++){
		f[i]=i;
	}
	if(cnt==k){
		kruscal();
		return 0;
	}
	for(int i=1;i<=m;i++){
		g[i]=edg[i];
	}mn=m;
	kr();
	flag=1;
	S=sum;
	dfs(1);
	printf("%lld",S);
	return 0;
}
 
