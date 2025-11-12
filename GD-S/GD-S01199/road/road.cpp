#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long minn=1e18;
int x,y,z;
int f[1005][1005];
int d[11][1005],d1[11];
int r[1005],l[1005];
int o[5005],o1[5005];
void js(int x,int y,int sum,long long ans)
{
//	cout<<x<<" "<<sum<<" "<<ans<<endl;
	if(sum==y+1)
	{
		minn=min(minn,ans);
		return;
	}
	for(int i=1; i<=n; i++)
	{
		if(l[i]!=1&&f[x][i]!=-1e9)
		{
			l[i]=1;
			js(i,y,sum+1,ans+f[x][i]);
			l[i]=0;
		}
		if(l[i]!=1)
		{
			for(int j=1; j<=k; j++)
			{
				if(d1[j]!=0)
				{
					l[i]=1;
					int kk=d1[j];
					d1[j]=0;
					js(i,y,sum+1,ans+d[j][i]+kk);
					d1[j]=kk;
					l[i]=0;
				}
				else
				{
					l[i]=1;
					js(i,y,sum+1,ans+d[j][i]);
					l[i]=0;
				}
			}
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	int s=0;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			f[i][j]=-1e9;
		}
	}
	for(int i=1; i<=n; i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		if(f[x][y]==-1e9) f[x][y]=f[y][x]=z;
		else f[x][y]=f[y][x]=min(z,f[x][y]);
	}
	int p=n;
	for(int i=1; i<=k; i++)
	{
		scanf("%d",&x);
		for(int j=1; j<=n; j++)
		{
			scanf("%d",&y);
			d[i][j]=y;
		}
		d1[i]=x;
	}
//	l[1]=1;
	js(1,n,1,0);
	printf("%lld",minn);
	return 0;
}
