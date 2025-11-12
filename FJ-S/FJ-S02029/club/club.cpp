#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,a[N][4];
long long ans;
void dfs(int x,int y,int k1,int k2,int k3,long long cnt)
{
	if(y==x)
	{
		ans=max(ans,cnt);
		return ;
	}
	for(int i=1;i<=3;i++)
	{
		if(k1<n/2&&i==1)
		{
			y++,k1++;
			dfs(x,y,k1,k2,k3,cnt+a[y][i]);
			y--;
		}
		if(k2<n/2&&i==2)
		{
			y++,k2++;
			dfs(x,y,k1,k2,k3,cnt+a[y][i]);
			y--;
		}
		if(k3<n/2&&i==3)
		{
			y++,k3++;
			dfs(x,y,k1,k2,k3,cnt+a[y][i]);
			y--;
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++)
		{
		 	st[i].x=0,st[i].y=0;
			md[i].x=0,md[i].y=0;
			f[i]=0;
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
				res[j]=0;
			}
		}
		if(n<=100)
		{
			dfs(n,0,0,0,0,0);
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=3;j++)
				{
					st[i].x=max(st[i].x,a[i][j]);
				}
				for(int j=1;j<=3;j++)
				{
					if(st[i].x==a[i][j])
					{
						st[i].y=j;
					}
				}
			}
			sort(st+1,st+n+1,cmp);
			for(int i=1;i<=n;i++)
			{
				if(res[st[i].y]==n/2)
				{
					continue;
				}
				ans+=st[i].x;
				res[st[i].y]++;
				f[i]=1;
			}	
			for(int i=1;i<=n;i++)
			{
				if(!f[i])
				{
					int res2=-1;
					for(int j=1;j<=3;j++)
					{
						if(a[i][j]==st[i].x)
						{
							continue;
						}
						res2=max(res2,a[i][j]);
					}
					md[i].x=res2;
					for(int j=1;j<=3;j++)
					{
						if(md[i].x==a[i][j])
						{
							md[i].y=j;
						}
					}
				}
			}
			sort(md+1,md+n+1,cmp);
			for(int i=1;i<=n;i++)
			{
				if(!f[i]&&md[i].x!=-1)
				{
					if(res[md[i].y]==n/2)
					{
						continue;
					}
					res[md[i].y]++;
					ans+=md[i].x;
					f[i]=1;
				}
			}
			for(int i=1;i<=n;i++)
			{
				if(!f[i])
				{
					for(int j=1;j<=3;j++)
					{
						if(res[j]<n/2)
						{
							ans+=a[i][j];
							f[i]=1;
							break;
						}
					}
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
