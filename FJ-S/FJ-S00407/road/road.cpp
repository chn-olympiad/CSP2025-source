#include<bits/stdc++.h>
#define int long long
#define R read()
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define gc getchar
using namespace std;
int read()
{
	int x=0,f=1;
	char c=gc();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=gc();}
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+c-48,c=gc();
	return x*f;
}
void write(int x,char xx)
{
	static int st[35],tot=0;
	if(x<0) putchar('-'),x=-x;
	do {st[++tot]=x%10,x/=10;}
	while(x);
	while(tot) putchar('0'+st[tot--]);
	putchar(xx);
}
#define M 1000010
#define N 20010
struct node{int u,v,w;};
bool operator<(node x,node y){return x.w<y.w;}
int n,m,k,c[20],a[20][N],ans,fa[N],num,nn,p[20],ni[20];
node e[M];
vector<node>V,Q;
int find(int x){return fa[x]==x?fa[x]:find(fa[x]);}
bool cmp(int x,int y){return ni[x]<ni[y];}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	nn=n=R,m=R,k=R;
	for(int i=1;i<=m;i++) e[i]={R,R,R};
	for(int i=1;i<=k;i++)
	{
		c[i]=R,p[i]=i;
		for(int j=1;j<=n;j++) a[i][j]=R;
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(e+1,e+m+1);
	for(int i=1,u,v,w;i<=m;i++)
	{
		u=e[i].u,v=e[i].v,w=e[i].w;
		if(find(u)!=find(v)) fa[find(u)]=find(v),ans+=w,V.push_back(e[i]);
	}
	for(int l=1,i,sum,u,v,w;l<=k;l++)
	{
		i=p[l],sum=c[i],Q.clear();
		for(int j=1;j<=n+1;j++) fa[j]=j;
		for(auto j:V) Q.push_back(j);
		for(int j=1;j<=nn;j++) Q.push_back({n+1,j,a[i][j]});
		sort(Q.begin(),Q.end());
		for(auto j:Q)
		{
			u=j.u,v=j.v,w=j.w;
			if(find(u)!=find(v)) sum+=w,fa[find(u)]=find(v);
		}
		ni[i]=sum;
	}
	sort(p+1,p+k+1,cmp);
	for(int l=1,i,sum,u,v,w;l<=k;l++)
	{
		i=p[l],sum=c[i]+num,Q.clear();
		for(int j=1;j<=n+1;j++) fa[j]=j;
		for(auto j:V) Q.push_back(j);
		for(int j=1;j<=nn;j++) Q.push_back({n+1,j,a[i][j]});
		sort(Q.begin(),Q.end());
		for(auto j:Q)
		{
			u=j.u,v=j.v,w=j.w;
			if(find(u)!=find(v)) sum+=w,fa[find(u)]=find(v);
		}
		if(sum<ans)
		{
			ans=sum,n++,num+=c[i];
			for(int j=1;j<=nn;j++) V.push_back({n,j,a[i][j]});
		}
	}
	write(ans,'\n');
	return 0;
}

