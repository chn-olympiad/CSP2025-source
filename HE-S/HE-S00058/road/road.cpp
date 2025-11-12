#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+5;
int n,m,k,c[N],a[15][N],fa[N],cnt;
long long ans;
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
struct edge{int u,v,val;}e[M],ne[M],re[M];
bool cmp(edge a,edge b){return a.val<b.val;}
edge MA(int a,int b,int c){edge r;r.u=a,r.v=b,r.val=c;return r;}
long long jisuan(int S){
	long long ans=0;
	for(int i=1;i<=cnt;i++) re[i]=ne[i];int y=cnt;
	for(int i=0;i<k;i++) if((1<<i)&S){
		ans+=c[i+1];
		for(int j=1;j<=n;j++){
			if(a[i+1][j]>ne[cnt].val) continue;
			re[++y]=MA(n+i+1,j,a[i+1][j]);
		}
	}
	for(int i=1;i<=n+k;i++) fa[i]=i; 
	sort(re+1,re+1+y,cmp);
	for(int i=1;i<=y;i++){
		int a=find(re[i].u),b=find(re[i].v);
		if(a!=b) fa[a]=b,ans+=re[i].val;
	}
	return ans;
}
void read(int &x){
	int t=0;char a=getchar();
	while(a<'0'||a>'9') a=getchar();
	while(a<='9'&&a>='0') t=t*10+a-'0',a=getchar();
	x=t;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n),read(m),read(k);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) read(e[i].u),read(e[i].v),read(e[i].val);
	for(int i=1;i<=k;i++){
		read(c[i]);
		for(int j=1;j<=n;j++) read(a[i][j]);
	}
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=m;i++){
		int x=find(e[i].u),y=find(e[i].v);
		if(x!=y) ans+=e[i].val,fa[x]=y,ne[++cnt]=MA(e[i].u,e[i].v,e[i].val);
	}
	for(int i=1;i<(1<<k);i++) ans=min(ans,jisuan(i));
	cout<<ans;
	return 0;
}
