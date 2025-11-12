#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T;
int a[N][5];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
			}
		}
		if(n==2)
		{
			int ans=0;
			for(int i=1;i<=3;i++)
			{
				for(int j=1;j<=3;j++)
				{
					if(i!=j)
					{
						ans=max(ans,a[1][i]+a[2][j]);
					}		
				}	
			} 
			cout<<ans<<endl;
		}
		else
		{
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				int x=0; 
				for(j=1;j<=3;j++)
				{
					x=max(x,a[i][j]);
				}
				ans=ans+x;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
} 
