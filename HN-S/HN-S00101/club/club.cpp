#include<bits/stdc++.h>
using namespace std;
int a[100001][4],ans=0,num1=0,num2=0,num3=0;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>a[i][2]&&a[i][1]>a[i][3])
			{
				num1++;
			}
			//cout<<num1;
			if(a[i][2]>a[i][1]&&a[i][2]>a[i][3])
			{
				num2++;
			}
			//cout<<num2;
			if(a[i][3]>a[i][2]&&a[i][3]>a[i][1])
			{
				num3++;
			}
			//cout<<num3;
			if(num1>n/2)
			{
				int mi=min(a[i][1],min(a[i+1][1],a[i-1][1]));
				if(mi==a[i][1])
				{
					ans+=max(a[i][2],a[i][3]);
				}
				if(mi==a[i+1][1])
				{
					ans+=max(a[i+1][2],a[i+1][3]);
				}
				else
				{
					ans+=max(a[i-1][2],a[i-1][3]);
				}
					
			}
			if(num2>n/2)
			{
				int mi2=min(a[i][2],min(a[i+1][2],a[i-1][2]));
				if(mi2==a[i][2])
				{
					ans+=max(a[i][1],a[i][3]);
				}
				if(mi2=a[i+1][2])
				{
					ans+=max(a[i+1][1],a[i+1][3]);
				}
				else 
				{
					ans+=max(a[i-1][1],a[i-1][3]);
				}
				
				
			}
			if(num3>n/2)
			{
				int mi3=min(a[i][3],min(a[i+1][3],a[i-1][3]));
				if(mi3==a[i][3])
				{
					ans+=max(a[i][2],a[i][1]);
				}
				if(mi3==a[i+1][3])
				{
					ans+=max(a[i+1][2],a[i+1][1]);
				}
				else
				{
					ans+=max(a[i-1][2],a[i-1][1]);
				}
			}
			else
			{
				ans+=max(a[i][1],max(a[i][2],a[i][3]));
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}
//Ren5Jie4Di4Ling5%
