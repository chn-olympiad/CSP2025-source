#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,c=0;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	if(k==1)
	{
		for(int i=0;i<n;i++)
		{
			if(a[i]==1)c++;
		}
		cout<<c; 
	 } 
	 else 
	 {	 	
		for(int i=0;i<n;i++)
		{ 
			int sum=a[i];	
			if(sum==k)
			{
				c++;
				sum=a[i+1];
				i++; 
			}
			for(int j=i+1;j<n;j++)
			{
				sum^=a[j];
				if(sum==k)
				{
					i=j-1;
					c++;
					break; 
				}
			}
		}
		cout<<c;
	 }
	return 0;
} 
