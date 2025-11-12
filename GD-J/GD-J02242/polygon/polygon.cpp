#include<bits/stdc++.h>
using namespace std;
long long n,k,a[5005],ans;
long long maxn=-1; 
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn=max(a[i],maxn);
	}
	if(n<=3)
	{
		if(n<3)
		{
			cout<<0;
			return 0;
		}
		else
		{
			if(max(a[1],max(a[2],a[3]))*2<a[1]+a[2]+a[3])
			{
				cout<<1;
				return 0;
			}
			else
			{
				cout<<0;
				return 0;
			}
		}
	}
	if(maxn==1)
	{
		cout<<n-2; 
	}
	return 0;
} 	
