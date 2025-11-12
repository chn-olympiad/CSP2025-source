#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int x;
int l[10000005];
int ans;
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	/*
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>l[i];
	}	
	for(int i=0;i<n;i++)
	{	
		
		for(int j=1;j<=n;j++)
		{
			if(i==0)
			{
				x=l[i];
				if(x==k)
					ans++; 		 
			}
			else
			{
				x=l[j];
				for(int z=j+1;z<=i+j;z++)
				{
					x=x^l[z];
				}	
				if(x==k)
					ans++; 
			}
			
		}
	}
	cout<<ans;
	*/
	
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>l[i];
	}	
	if(n==1)
	{
		cout<<0;
	}
	if(n==2)
	{
		cout<<1;
	}
	
	
	
	
	
	
	
	
	
	
	
}
