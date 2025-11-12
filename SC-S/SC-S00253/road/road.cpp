#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+10,maxm=1e6+10,maxk=1e1+3;
const ll inf=1e18+10;
int n,m,k,cnte,low;
ll ans,res;
int c[maxk],a[maxk][maxn],fa[maxn+maxk];
struct EDGE{
	int u,v,w;
}e[maxm],e1[maxm<<1];
bool cmp(EDGE x,EDGE y) {return x.w<y.w;}
int find(int x) {return x==fa[x]?x:fa[x]=find(fa[x]);}
int read()
{
	int ret=0,w=1;char ch=0;
	while(ch<'0'||ch>'9') {if(ch=='-') w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') {ret=(ret<<3)+(ret<<1)+(ch^48);ch=getchar();}
	return ret*w;
}
void inpu()
{
	ans=inf;
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++) e[i].u=read(),e[i].v=read(),e[i].w=read();
	for(int i=1;i<=k;i++)
	{
		c[i]=read();
		for(int j=1;j<=n;j++) a[i][j]=read();
	}
}
bool check()
{
	for(int i=1;i<=k;i++) if(c[i]) return false;
	return true;
}
void krs(int x)
{
	int use=0;
	sort(e1+1,e1+cnte+1,cmp);
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=1;i<=cnte;i++)
	{
		int fa1=find(e1[i].u),fa2=find(e1[i].v);
		if(fa1!=fa2) fa[fa2]=fa1,res+=e1[i].w,use++;
		if(use==n+x-1) break;
	}
}
void deal()
{
	for(int i=low;i<(1<<k);i++)
	{
		int num=0;
		cnte=0;res=0;
		for(int j=1;j<=m;j++) e1[++cnte]=(EDGE){e[j].u,e[j].v,e[j].w};
		for(int j=1;j<=k;j++) if(i&(1<<(j-1)))
		{
			res+=c[j],num++;
			for(int p=1;p<=n;p++) e1[++cnte]=(EDGE){j+n,p,a[j][p]};
		}
		krs(num);
		ans=min(ans,res);
	}
}
void solve()
{
	inpu();
	if(check()) low=(1<<k)-1;
	deal();
	printf("%lld",ans);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int t=1;
	while(t--) solve();
	return 0;
}