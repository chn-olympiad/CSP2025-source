#include<bits/stdc++.h>
using namespace std;
long long n,m,k,fa[10007],c[17],f1[17][10007],ans=0,cnt=0,sum[17],A=1,v[17];
int find(int x)
{
	if(fa[x]==x)
	{
		return x;
	}
	return fa[x]=find(fa[x]);
}
void bj(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x!=y)
	{
		fa[y]=x;
	}
	return ;
}
struct N{
	long long x,y,w;
}f[1000007];
bool cmp(N x,N y)
{
	return x.w<y.w;
}
void scs()
{
	ans=0;
	cnt=0;
	sort(f+1,f+1+m,cmp);
	for(int i=1;i<=m;i++)
	{
		if(find(f[i].x)!=find(f[i].y))
		{
			bj(f[i].x,f[i].y);
			ans+=f[i].w;
			cnt++;
		}
		if(cnt==n-1)
		{
			break;
		}
	}
	return ;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>f[i].x>>f[i].y>>f[i].w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		if(c[i]!=0)
		{
			A=0;
		}
		for(int j=1;j<=n;j++)
		{
			cin>>f1[i][j];
			if(f1[i][j]!=0)
			{
				A=0;
			}			
		}
	}
	if(k==0)
	{
		scs();
		cout<<ans;
		return 0;
	}
	else if(A==1)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=m;j++)
		{
			f[j].w=min(f[j].w,f1[i][f[j].x]+f1[i][f[j].y]);
		}
	}
	scs();
	cout<<ans;
	return 0;
}
