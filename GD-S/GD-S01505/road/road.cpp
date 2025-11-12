#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,c[11],a[10010][11],fa[10010],cnt,ans;
struct node{
	int u,v,w;
}e[2000010];
int read(){
	int cnt=0,f=1;char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-1;
	for(;isdigit(ch);ch=getchar()) cnt=cnt*10+ch-'0';
	return cnt*f;
}
bool cmp(node x,node y){
	return x.w<y.w;
}
int find(int x){
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}
void prim(){
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(e+1,e+cnt+1,cmp);
	int res=0;
	for(int i=1;i<=cnt;i++){
		int fu=find(e[i].u);
		int fv=find(e[i].v);
		if(fu!=fv){
			fa[fv]=fu;
			res++;
			ans+=e[i].w;
			if(res==n-1) return;
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		e[i].u=read();e[i].v=read();e[i].w=read();
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++){
			a[j][i]=read()+c[i];
		}
	}
	cnt=m;
	for(int i=1;i<=k;i++){
		for(int u=1;u<=n;u++){
			for(int v=u+1;v<=n;v++){
				e[++cnt].u=u;e[cnt].v=v;e[cnt].w=a[u][i]+a[i][v];
				e[++cnt].u=v;e[cnt].v=u;e[cnt].w=a[v][i]+a[i][u];
			}
		}
	}
	prim();
	cout<<ans;
	return 0;
}
