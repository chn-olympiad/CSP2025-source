// GZ-S00334 王曦 贵阳华师一学校 
#include <bits/stdc++.h>

using namespace std;

int rd() {
	int x=0; bool f=0; char ch=getchar();
	while(ch<'0' || ch>'9') {if(ch=='-') f=1; ch=getchar();}
	while(ch>='0' && ch<='9') x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return f?-x:x;
}

#define x first
#define y second
#define pb emplace_back
#define upb upper_bound
#define lowb lower_bound
#define fil(a,x) memset(a,x,sizeof(a))
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

typedef long long LL;
typedef vector<int> VI;
typedef unsigned int ull; 
typedef pair<int,int> PII;
const int N=1.1e4+10,M=1.1e6+10;

int n,m,K; LL ans=0;
int pa[N];
struct Edge {int u,v,w,tp;}e[M];
int c[N];

bool cmp1(Edge a,Edge b) {return a.w<b.w;} 
int fd(int x) {return pa[x]==x?x:pa[x]=fd(pa[x]);}

signed main() 
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	n=rd(),m=rd(),K=rd();
	rep(i,1,n+K) pa[i]=i;
	for(int i=1;i<=m;i++) e[i].u=rd(),e[i].v=rd(),e[i].w=rd(),e[i].tp=0;
	sort(e+1,e+1+m,cmp1); int m2=0;
	rep(i,1,m) {
		int u=fd(e[i].u),v=fd(e[i].v),w=e[i].w;
		if(u!=v) pa[u]=v,ans+=w,e[++m2]=e[i];
	}
	m=m2;
	
	rep(i,1,K) {
		c[i]=rd();
		rep(j,1,n) ++m,e[m].u=i+n,e[m].v=j,e[m].w=rd(),e[m].tp=i;
	}
	sort(e+1,e+1+m,cmp1);
	for(int s=1;s<(1<<K);s++) {
		LL res=0;
		rep(i,1,K) if(s>>(i-1)&1) res+=c[i];
		rep(i,1,n+K) pa[i]=i;
		rep(i,1,m) if(!e[i].tp || s>>(e[i].tp-1)&1) {
			int u=fd(e[i].u),v=fd(e[i].v),w=e[i].w;
			if(u!=v) pa[u]=v,res+=w;
		}
		ans=min(ans,res);
	} 
	printf("%lld\n",ans);
	
//	cerr<<clock()*1.0/CLOCKS_PER_SEC<<"\n";
	
	return 0;
}

