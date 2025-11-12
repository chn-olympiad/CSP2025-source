#include<bits/stdc++.h>
#define lowbit(x) (x&-x)
using namespace std;
const int maxn=1025;
using ll=long long;
int n,m,k;
struct Edge
{
	int u,v,w;
};
vector<Edge>e[maxn],e1,e2[15];
ll c[15];
int f[20005],siz[20005];
inline int getfa(int x){return f[x]==x?x:f[x]=getfa(f[x]);}
ll ans,minn;
bool cmp(Edge x,Edge y)
{
	return x.w<y.w;
}
int read()
{
	int x=0;
	char c=getchar();
	for(;!isdigit(c);c=getchar());
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	return x;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=read();
		e1.push_back({u,v,w});
	}
	
	sort(e1.begin(),e1.end(),cmp);
	for(int i=1;i<=n;i++)f[i]=i,siz[i]=1;
	for(int i=0;i<m;i++)
	{
		int ru=getfa(e1[i].u),rv=getfa(e1[i].v);
		if(ru!=rv)
		{
			if(siz[ru]>siz[rv])swap(ru,rv);
			f[ru]=rv,siz[rv]+=siz[ru];
			ans+=e1[i].w;
			e[0].push_back(e1[i]);
		}
	}
	minn=ans;
	for(int i=1;i<=k;i++)
	{
		c[i]=read();
		for(int j=1;j<=n;j++)
		{
			ll w=read();
			e2[i].push_back({i+n,j,w});
		}
		sort(e2[i].begin(),e2[i].end(),cmp);
	}
	for(int i=1;i<(1<<k);i++)
	{
		ans=0;
		int p=0;
		for(int j=k-1;j>=0;j--)if(i&(1<<j))ans+=c[j+1],p=j+1;
		for(int j=1;j<=k+n;j++)f[j]=j,siz[j]=1;
		int p1=i-lowbit(i);
		int q1=0,q2=0;
		while(1)
		{
			if(q1==e[p1].size() && q2==e2[p].size())break;
			if(q1!=e[p1].size() && (q2==e2[p].size() || e[p1][q1].w<e2[p][q2].w))
			{
				int ru=getfa(e[p1][q1].u),rv=getfa(e[p1][q1].v);
				if(ru!=rv)
				{
					if(siz[ru]>siz[rv])swap(ru,rv);
					f[ru]=rv,siz[rv]+=siz[ru];
					ans+=e[p1][q1].w;
					e[i].push_back(e[p1][q1]);
				}
				q1++;
			}
			else
			{
				int ru=getfa(e2[p][q2].u),rv=getfa(e2[p][q2].v);
				if(ru!=rv)
				{
					if(siz[ru]>siz[rv])swap(ru,rv);
					f[ru]=rv,siz[rv]+=siz[ru];
					ans+=e2[p][q2].w;
					e[i].push_back(e2[p][q2]);
				}
				q2++;
			}
		}
		minn=min(minn,ans);
	}
	printf("%lld",minn);
	return 0;
}
