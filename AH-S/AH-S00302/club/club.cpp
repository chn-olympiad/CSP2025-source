#include<bits/stdc++.h>
using namespace std;

int t;
const int M=100005;

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[M],b[M];
		if(n==2)
		{
			for(int i=1;i<=3;i++)
			{
				cin>>a[i];
			}
			for(int i=1;i<=3;i++)
			{
				cin>>b[i];
			}
			int ans=0;
			for(int i=1;i<=3;i++)
			{
				for(int j=1;j<=3;j++)
				{
					if(i!=j)
					{
						ans=max(ans,a[i]+b[j]);
					}
				}
			}
			cout<<ans<<endl;
		}
		else
		{
			int ax[M],ay[M],az[M],ans=0;
			bool flag=0;
			for(int i=1;i<=n;i++)
			{
				cin>>ax[i]>>ay[i]>>az[i];
				if(ay[i]!=0||az[i]!=0)
				{
					flag=1;
				}
			}
			if(flag==0)
			{
				sort(ax+1,ax+n+1);
				for(int i=n;i>n/2;i--)
				{
					ans+=ax[i];
				}
				cout<<ans<<endl;
			}
		}
	}
	return 0;
}
