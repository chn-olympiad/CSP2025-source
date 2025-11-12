#include<bits/stdc++.h>
#define int long long
using namespace std;
char buf[1000005],*p1,*p2;
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++)
int read(){
	int x=0,f=0;char c=gc();
	while(!isdigit(c))f|=(c=='-'),c=gc();
	while(isdigit(c))x=(x<<1)+(x<<3)+(c^48),c=gc();
	return f?-x:x;
}
int n,m,k,ans,fa[10015],c[15],a[15][10005];
struct edge{
	int u,v,w;
	bool operator<(const edge &t)const{return w<t.w;}
}e[1000005],ff[200005];
int find(int x){
	if(fa[x]==x)return x;
	else return fa[x]=find(fa[x]);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)e[i].u=read(),e[i].v=read(),e[i].w=read();
	sort(e+1,e+m+1);
	for(int i=1;i<=n;i++)fa[i]=i;
	ans=1e18;
	int res=0,tot=0;
	for(int i=1;i<=m;i++){
		int c=find(e[i].u),d=find(e[i].v);
		if(c!=d){
			fa[c]=d;
			res+=e[i].w;
			e[++tot]=e[i];
		}
	}
	ans=res;
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++)a[i][j]=read();
	}
	for(int s=1;s<(1<<k);s++){
		int num=tot;
		for(int j=1;j<=n+k;j++)fa[j]=j;
		for(int j=1;j<=num;j++)ff[j]=e[j];
		int res=0;
		for(int j=1;j<=k;j++){
			if(s>>(j-1)&1){
				res+=c[j];
				for(int i=1;i<=n;i++)ff[++num]=edge({i,j+n,a[j][i]});
			}
		}
		if(res>ans)continue;
		sort(ff+1,ff+num+1);
		for(int i=1;i<=num;i++){
			int c=find(ff[i].u),d=find(ff[i].v);
			if(c!=d){
				res+=ff[i].w;
				fa[c]=d;
			}
		}
		ans=min(ans,res);
	}
	printf("%lld",ans);
	return 0;
}
