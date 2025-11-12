#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
int n,t;
int ans=0;
int x[MAXN],y[MAXN],z[MAXN],m[MAXN],pd[MAXN];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i]>>z[i];
	}
	if(y[1]==0&&z[1]==0)
	{
		sort(x+1,x+n+1);
		for(int i=n;i>n/2;i--)
		{
			ans+=x[i];
		}
		cout<<ans;
		return ;
	}
	else if(z[1]==0&&z[2]==0)
	{
		sort(x+1,x+n+1);
		sort(y+1,y+n+1);
		for(int i=n;i>n/2;i--)
		{
			ans+=x[i];
			ans+=y[i];
		}
		cout<<ans;
		return ;
	}
	else if(n<=2)
	{
		m[1]=max(x[1],y[1]);
		m[1]=max(m[1],z[1]);
		m[2]=max(x[2],y[2]);
		m[2]=max(m[2],z[2]);
		if(m[1]==x[1])
		{
			pd[1]=1;
		}
		else if(m[1]==y[1])
		{
			pd[1]=2;
		}
		else
		{
			pd[1]=3;
		}
		if(m[2]==x[2])
		{
			pd[2]=1;
		}
		else if(m[1]==y[1])
		{
			pd[2]=2;
		}
		else
		{
			pd[2]=3;
		}
		if(pd[1]!=pd[2])
		{
			ans+=m[1]+m[2];
		}
		else
		{
			if(m[1]>m[2])
			{
				ans+=m[1];
				for(int i=1;i<=3;i++)
				{
					if(pd[2]==1)
					{
						m[2]=max(y[2],z[2]);
					}
					else if(pd[2]==2)
					{
						m[2]=max(x[2],z[2]);
					}
					else
					{
						m[2]=max(y[2],x[2]);
					}
				}
				ans+=m[2];
			}
			else if(m[1]<m[2])
			{
				ans+=m[2];
				for(int i=1;i<=3;i++)
				{
					if(pd[1]==1)
					{
						m[1]=max(y[1],z[1]);
					}
					else if(pd[1]==2)
					{
						m[1]=max(x[1],z[1]);
					}
					else
					{
						m[1]=max(y[1],x[1]);
					}
				}
				ans+=m[1];
			}
			else
			{
				ans+=m[2];
				for(int i=1;i<=3;i++)
				{
					if(pd[1]==1)
					{
						m[1]=max(y[1],z[1]);
					}
					else if(pd[1]==2)
					{
						m[1]=max(x[1],z[1]);
					}
					else
					{
						m[1]=max(y[1],x[1]);
					}
				}
				for(int i=1;i<=3;i++)
				{
					if(pd[2]==1)
					{
						m[2]=max(y[2],z[2]);
					}
					else if(pd[2]==2)
					{
						m[2]=max(x[2],z[2]);
					}
					else
					{
						m[2]=max(y[2],x[2]);
					}
				}
				ans+=max(m[1],m[2]);
			}
		}
		cout<<ans;
		return ;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
