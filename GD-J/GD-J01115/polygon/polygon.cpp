#include<bits/stdc++.h>
using namespace std;
int a[3];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
    	cin>>a[i];
	}
	if(n<=3)
	{
		if(n==3)
		{
			if(a[0]+a[1]>a[2] and a[0]+a[2]>a[1] and a[1]+a[2]>a[0])
			{
				cout<<1%998244353
				;
				return 0;
			}
			else
			{
				cout<<0%998244353;
				return 0;
			}
		}
		else
		{
			cout<<0%998244353;
			return 0;
		}
	}
	else
	{
		cout<<(n-2)%998244353;
		return 0;
	}
 } 
