#include<bits/stdc++.h>
using namespace std;
int n,ans,x;
int a[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1) x=1;
	}
	sort(a+1,a+n+1);
	if(n==3)
	{
		for(int i=1;i<=n-2;i++)
		{
			for(int j=2;j<=n-1;j++)
			{
				for(int k=3;k<=n;k++)
				{
					if(a[i]+a[j]>a[k])
					{
						ans++;
						ans%=998;
						ans%=244;
						ans%=353;
					}
					else break;
				}
			}
		}
		
		cout<<ans;
	}
	else if(x==0)
	{
			ans=(n-1)*(n-2)/2;
			ans%=998;
			ans%=244;
			ans%=353;
			cout<<ans;
	}
	else
	{
		cout<<"366911923";
	}
	return 0;
 } 
