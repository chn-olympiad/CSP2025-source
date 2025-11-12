#include<bits/stdc++.h>
#define IL inline
#define mp make_pair
#define pb push_back
#define rpt(a,b,c) for(int a=b;a<=c;a++)
#define tpr(a,b,c) for(int a=b;a>=c;a--)
using namespace std;
typedef long long LL;
const int N=1e6+10;
const LL inf=1e18;
struct edge{
	int u,v,w;
	IL bool operator < (const edge &f)const{return w<f.w;}
}e[N];
int n,m,k,x;
namespace DSU{
	int fa[N];
	void fainit(){rpt(i,1,n+k)fa[i]=i;}
	int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
	void Merge(int x,int y){
		if((x=find(x))==(y=find(y)))return ;
		fa[x]=y;
	}
}using namespace DSU;

int tp,c[N];
void einit(){
	fainit();
	sort(e+1,e+m+1);
	rpt(i,1,m)if(find(e[i].u)!=find(e[i].v))
		e[++tp]=e[i],Merge(e[i].u,e[i].v);
}
LL ans=inf;
IL int read(){
	int x=0; char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	n=read(),m=read(),k=read();
	rpt(i,1,m)e[i].u=read(),e[i].v=read(),e[i].w=read();
	einit();
	
	rpt(i,1,k){
		c[i]=read();
		rpt(j,1,n)x=read(),e[++tp]={n+i,j,x};
	}
	sort(e+1,e+tp+1);
	rpt(s,0,(1<<k)-1){
		fainit();
		LL sum=0;
		rpt(i,1,k)if(s>>(i-1)&1)sum+=c[i];
		rpt(i,1,tp)if(e[i].u<=n||(s>>(e[i].u-n-1)&1)){
			if(find(e[i].u)!=find(e[i].v)){
				Merge(e[i].u,e[i].v),sum+=e[i].w;
			}
		}
		ans=min(ans,sum);
	}
	printf("%lld",ans);
	return 0;
}

