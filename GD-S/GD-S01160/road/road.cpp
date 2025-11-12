#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+5,K=15,M=1e6+5;

int n,m,k,cnt,ans;
int c[N];
int a[K][N];
int f[N];
ll mm;

struct Node{
	int u,v,w;
}e[M+(N*K)];

int find(int x)
{
	if(f[x]!=x) f[x]=find(f[x]);
	return f[x];
}

bool cmp(Node x,Node y)
{
	return x.w<y.w;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++)
	{
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	mm=m;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int kk=1;kk<=k;kk++)
	{
		for(int i=1;i<n;i++)
	    {
		    for(int j=i+1;j<=n;j++)
		    {
		    	int res=c[kk]+a[kk][i]+a[kk][j];
		    	e[++mm].w=res;
		    	e[mm].u=i;
		    	e[mm].v=j;
		    }
	    }
	}
	sort(e+1,e+mm+1,cmp);
	for(int i=1;i<=mm;i++)
	{
		int u=e[i].u,v=e[i].v,w=e[i].w;
		int fu=find(u),fv=find(v);
		if(fu!=fv)
		{
			f[u]=f[e[i].v];
			ans+=w;
			cnt++;
		}
		if(cnt==n-1) break;
	}
	cout<<ans<<"\n";
	return 0;
}
