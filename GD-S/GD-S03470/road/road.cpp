#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+50,M=1e6+5,K=10,S=1<<K;
struct Edge{
	int u,v,w;
}e[M],a[K][N],f[S][N];
int n,m,k,fa[N],z[N],c[K],fn[S];
ll ans=1e18,s;
bool cmp(Edge x,Edge y){return x.w<y.w;}
int getfa(int x){return fa[x]==x?x:fa[x]=getfa(fa[x]);}
void init(){s=0;for(int i=1;i<=n+k;i++)fa[i]=i,z[i]=1;}
void merge(int x,int y){
	if(z[x]>z[y])swap(x,y);
	fa[x]=y,z[y]+=z[x];
}
int read(){
	int x=0;char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)e[i]={read(),read(),read()};
	sort(e+1,e+m+1,cmp);init();
	for(int i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		int up=getfa(u),vp=getfa(v);
		if(up!=vp)merge(up,vp),s+=w,f[0][++fn[0]]=e[i];
	}
	ans=min(ans,s);
	for(int i=0;i<k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++){
			int x=read();
			a[i][j]={i+n+1,j,x};
		}
		sort(a[i]+1,a[i]+n+1,cmp);
	}
	for(int i=1;i<1<<k;i++){
		int lst,wh;init();
		for(int j=0;j<k;j++)
			if((1<<j)&i)
				lst=j,s+=c[j];
		wh=i^(1<<lst);
		int l=1,r=1,sl=0,len=fn[wh];
		while(l<=n&&r<=len)
			if(a[lst][l].w>f[wh][r].w)++sl,e[sl]=f[wh][r],++r;
			else ++sl,e[sl]=a[lst][l],++l;
		while(l<=n)++sl,e[sl]=a[lst][l],++l;
		while(r<=len)++sl,e[sl]=f[wh][r],++r;
		for(int j=1;j<=sl;j++){
			int u=e[j].u,v=e[j].v,w=e[j].w;
			int up=getfa(u),vp=getfa(v);
			if(up!=vp)merge(up,vp),s+=w,f[i][++fn[i]]=e[j];
		}
		ans=min(ans,s);
	}
	printf("%lld",ans);
	
	return 0;
} 
