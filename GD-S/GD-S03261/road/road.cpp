#include<bits/stdc++.h>
using namespace std;
struct jie
{
	int u,v,w;
}a[1100005],bf[1100005];
int c[15],b[15][10005];
bool cmp(jie s1,jie s2)
{
	return s1.w<s2.w;
}
int cjs[10005],ym;
int bcj(int p)
{
	if (cjs[p]==p)
	{
		return p;
	}
	else
	{
		return cjs[p]=bcj(cjs[p]);
	}
}
long long sum=100000000000000;
int n,m,k,km;
void dfs(int p,long long ans)
{
	if (p==k+1)
	{
		//sort(bf+1,bf+m+1,cmp);
		long long qz=0;
		for (int j=1;j<=n;j++)
		{
			cjs[j]=j;
		}
		for (int j=1;j<=m;j++)
		{
			bf[j]=a[j];
		}
		int zx=1,yx=1;
		sort(bf+1,bf+m+1,cmp);
		for (int i=1;i<=m;i++)
		{
				if (bcj(bf[i].u)!=bcj(bf[i].v))
				{
					qz=qz+bf[i].w;
					cjs[bcj(bf[i].u)]=bcj(bf[i].v);
				}
		}
		sum=min(sum,ans+qz);
		return;
	}
	else
	{
		int zxz=1000000001,zxw=0;
		for (int j=1;j<=n;j++)
		{
			if (b[p][j]<zxz)
			{
				zxw=j;
				zxz=b[p][j];
			}
		}
		for (int j=1;j<=n;j++)
		{
			m=m+1;
			a[m].u=j;
			a[m].v=zxw;
			a[m].w=zxz+b[p][j];
		}
		dfs(p+1,ans+c[p]);
		for (int j=1;j<=n;j++)
		{
			m=m-1;
		}
		dfs(p+1,ans);
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	ym=m;
	long long ans=0;
	for (int i=1;i<=m;i++)
	{
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	if (k>5)
	{
		int q=0;
		for (int i=1;i<=k;i++)
		{
			cin>>c[i];
			for (int j=1;j<=n;j++)
			{
				cjs[j]=j;
				cin>>b[i][j];
			}
			if (c[i]!=0)
			{
				q=1;
			}
			else
			{
				int zxz=1000000001,zxw=0;
				for (int j=1;j<=n;j++)
				{
					if (b[i][j]<zxz)
					{
						zxw=j;
						zxz=b[i][j];
					}
				}
				for (int j=1;j<=n;j++)
				{
					m=m+1;
					a[m].u=j;
					a[m].v=zxw;
					a[m].w=zxz+b[i][j];
				}
			}
		}
		sort(a+1,a+m+1,cmp);
		//cout<<m<<endl;
		for (int i=1;i<=m;i++)
		{
			//cout<<a[i].u<<" "<<a[i].v<<" "<<a[i].w<<endl;
			if (bcj(a[i].u)!=bcj(a[i].v))
			{
				ans=ans+a[i].w;
				cjs[bcj(a[i].u)]=bcj(a[i].v);
			}
		}
		cout<<ans<<endl;
	}
	else
	{
		for (int i=1;i<=k;i++)
		{
			cin>>c[i];
			for (int j=1;j<=n;j++)
			{
				cjs[j]=j;
				cin>>b[i][j];
			}
		}
		sort(a+1,a+m+1,cmp);
		dfs(1,0);
		cout<<sum<<endl;
	}
}
