#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+5,M=1e6+5,K=12;
const ll inf=1e18;
int n,m,k,t[K][N],g[N],fa[N],p[K];
ll ans=inf;
struct node{int u,v,w;}s[M*3],ss[N];
bool cmp(node x,node y){return x.w<y.w;}
int read(){
	int res=0;char c=getchar();
	while(c<'0'||c>'9'){c=getchar();}
	while('0'<=c&&c<='9'){res=res*10+c-'0';c=getchar();}
	return res;
}int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void solve(){
	ll res=0;int cnt=m,tot=n-1,a,b;
	for(int i=n+k;i;i--) fa[i]=i;
	for(int i=1;i<=m;i++) s[i].u=ss[i].u,s[i].v=ss[i].v,s[i].w=ss[i].w;
	for(int i=1;i<=k;i++) if(p[i]){
		res+=g[i];tot++;
		for(int j=1;j<=n;j++) ++cnt,s[cnt].u=n+i,s[cnt].v=j,s[cnt].w=t[i][j];
	}sort(1+s,1+cnt+s,cmp);
	for(int i=1;i<=cnt;i++){
		if((a=find(s[i].u))==(b=find(s[i].v))) continue;
		fa[a]=b;res+=s[i].w;
		if(res>=ans) return;
		if((--tot)==0){ans=min(ans,res);return;}
	}
}void dfs(int x){
	if(x>k){solve();return;}
	p[x]=0;dfs(x+1);p[x]=1;dfs(x+1);
}int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=1;i<=m;i++) ss[i].u=read(),ss[i].v=read(),ss[i].w=read();
	for(int i=1;i<=k;i++){
		g[i]=read();
		for(int j=1;j<=n;j++) t[i][j]=read();
	}dfs(1);
	printf("%lld",ans);
	fclose(stdin);fclose(stdout); 
return 0;}
