#include <bits/stdc++.h>
using namespace std;
int a[100005][3],h,n,s[100005],ans;
bool d;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>h;
	d=0;
	while(h--)
	{
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
			ans=max(ans,max(max( a[1][1]+a[2][2]  ,a[1][1]+a[2][3]   ),max(max( a[1][2]+a[2][1]  , a[1][2]+a[2][3]  ),max( a[1][3]+a[2][1]  ,  a[1][3]+a[2][2] ))));
			cout<<ans<<endl;
		}
		
		
		
		
		
		for(int i=1;i<=n;i++)
		{
			for(int j=2;j<=3;j++)
			{
				if(a[i][j]!=0)
				{
					d=1;
					break;
				}
			}
		}
		if(d!=1)
		{
			
			for(int i=1;i<=n;i++)
			{
				s[i]=a[i][1];
			}
			sort(s+1,s+1+n);
			for(int i=n;i>n/2;i--)
			{
				ans+=s[i];
			}
			cout<<ans<<endl;
		}
		
		
		
		
		
		ans=0;
		for(int i=1;i<=n;i++)
		{
			s[i]=0;
			for(int j=1;j<=3;j++)
			{
				a[i][j]=0;
			}
		}
		
		d=0;
	}
	
	
	
	
	return 0;
}
