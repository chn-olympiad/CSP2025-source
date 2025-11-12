#include<bits/stdc++.h>
using namespace std;
int T,n,m,ans,a[100005],x[100005],y[100005],z[100005],t[5],bz[100005],r;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while (T--)
	{
		cin>>n;
		m=n/2;r=0;ans=0;
		for (int i=1;i<=3;i++) t[i]=0;
		for (int i=1;i<=n;i++)
		{
			scanf("%d %d %d",&x[i],&y[i],&z[i]);
			if (x[i]>=y[i]&&x[i]>=z[i])
			{
				bz[i]=1;
				t[1]++;
			}
			else if (y[i]>=z[i])
			{
				bz[i]=2;
				t[2]++;
			}
			else
			{
				bz[i]=3;
				t[3]++;
			}
		}
		if (t[1]>m)
		{
			for (int i=1;i<=n;i++)
			{
				if (bz[i]==1)
				{
					r++;
					a[r]=x[i]-max(y[i],z[i]);
					ans+=x[i];
				}
				else
				{
					if (bz[i]==2)
					{
						ans+=y[i];
					}
					else
					{
						ans+=z[i];
					}
				}
			}
			sort(a+1,a+r+1);
			for (int i=1;i<=r-m;i++)
			{
				ans-=a[i];
			}
		}
		else if (t[2]>m)
		{
			for (int i=1;i<=n;i++)
			{
				if (bz[i]==2)
				{
					r++;
					a[r]=y[i]-max(x[i],z[i]);
					ans+=y[i];
				}
				else
				{
					if (bz[i]==1)
					{
						ans+=x[i];
					}
					else
					{
						ans+=z[i];
					}
				}
			}
			sort(a+1,a+r+1);
			for (int i=1;i<=r-m;i++)
			{
				ans-=a[i];
			}
		}
		else if (t[3]>m)
		{
			for (int i=1;i<=n;i++)
			{
				if (bz[i]==3)
				{
					r++;
					a[r]=z[i]-max(x[i],y[i]);
					ans+=z[i];
				}
				else
				{
					if (bz[i]==2)
					{
						ans+=y[i];
					}
					else
					{
						ans+=x[i];
					}
				}
			}
			sort(a+1,a+r+1);
			for (int i=1;i<=r-m;i++)
			{
				ans-=a[i];
			}
		}
		else
		{
			for (int i=1;i<=n;i++)
			{
				if (bz[i]==1) ans+=x[i];
				if (bz[i]==2) ans+=y[i];
				if (bz[i]==3) ans+=z[i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
