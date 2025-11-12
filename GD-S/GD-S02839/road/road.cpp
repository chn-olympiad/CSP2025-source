#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+5,K=12,KK=(1<<10)+5;
int n,m,k,kk,a[K][N],c[K],cnt,p[N+K],ss[K];
int getr(int x){return x==p[x]?x:p[x]=getr(p[x]);}
struct edg{int u,v,w;}e[M+N*K];
bool operator<(const edg a,const edg b){return a.w<b.w;}
long long ans=1e18,res;
bool A=1;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;cnt=m;kk=(1<<k)-1;
	for(int i=1,u,v,w;i<=m;i++)
		cin>>u>>v>>w,e[i]={u,v,w};
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		if(c[i]!=0) A=0;
		for(int j=1,x;j<=n;j++)
		{
			cin>>x;
			if(x==0) ss[i]=j;
			a[i][j]=x;
		}
		if(!ss[i]) A=0;
	}
//	cout<<A<<'\n';
	if(A)
	{
		for(int i=1;i<=k;i++)
			for(int j=1;j<=n;j++)
				e[++cnt]={ss[i],j,a[i][j]};
		sort(e+1,e+1+cnt);
		for(int i=1;i<=n;i++) p[i]=i;
		for(int i=1,r=0;i<=cnt&&r<=n-1;i++)
			if(getr(e[i].u)!=getr(e[i].v))
				p[p[e[i].u]]=p[e[i].v],r++,res+=e[i].w;
		cout<<res;
		return 0;
	}
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n;j++)
			e[++cnt]={n+i,j,a[i][j]};
	sort(e+1,e+1+cnt);
	for(int S=0,xx;S<=kk;S++)
	{
		res=xx=0;
		for(int i=0;i<k;i++)
			if(S&(1<<i)) res+=c[i+1],xx++;
		for(int i=1;i<=n+k;i++) p[i]=i;
		for(int i=1,r=0;i<=cnt&&r<=n-1+xx;i++)
			if(e[i].u<=n||(S&(1<<(e[i].u-n-1))))
				if(getr(e[i].u)!=getr(e[i].v))
					p[p[e[i].u]]=p[e[i].v],r++,res+=e[i].w;
		ans=min(ans,res);
	}
	cout<<ans;
}
