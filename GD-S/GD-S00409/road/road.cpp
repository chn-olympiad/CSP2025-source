#include<bits/stdc++.h>
#define int long long
#define mp make_pair 
#define _ 10005
#define __ 3000005
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x*f;
}
int n,m,k,cnum,cntm;
int a[15][_],c[15];
int fa[_];
struct edge{
	int u,v,w;
	bool operator<(const edge&q)const{return w<q.w;}
}e[__];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);} 
int prim(int m){
	int ans=0,cntt=0;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		if(cntt>=n-1)break;
		int u=e[i].u,v=e[i].v,w=e[i].w;
		int fu=find(fa[u]),fv=find(fa[v]);
		if(fu^fv)ans+=w,fa[fu]=fv,++cntt;
	}
	return ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=cntm=read(),k=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
//		p[mp(u,v)]=p[mp(v,u)]=w;
		e[i]=(edge){u,v,w};
	}
	for(int i=1;i<=k;i++){
		c[i]=read(),cnum+=c[i];
		for(int j=1;j<=n;j++)a[i][j]=read();
	}
	if(cnum==0){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				if(a[i][j]==0){
					for(int l=1;l<=n;l++){
						if(j^l)e[++cntm]=(edge){j,l,a[i][l]};
					}
				}
			}
		}
	}
	sort(e+1,e+cntm+1);
	printf("%lld\n",prim(cntm));
	return 0;
}
