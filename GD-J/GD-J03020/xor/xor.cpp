#include<bits/stdc++.h>
using namespace std;

int main()
{
	
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	int n, k;
	
	cin>>n>>k;
	
	int a[500007]{};
	
	bool c=false;
	
	for(int i=1;i<=n;i++)
	{
		
		cin>>a[i];
		
		if(a[i]==1)
		{
			
			c=true;
			
		}
		
	}
	
	if(n<=2&&k==0)
	{
		
		if(a[1]==0)
		{
			
			if(a[2]==0)
			{
				
				cout<<2;
				return 0;
				
			}
			else
			{
				
				cout<<1;
				return 0;
				
			}
			
		}
		else if(a[2]==0)
		{
			
			cout<<1;
			return 0;
			
		}
		
		int ls=a[1]^a[2]; 
		
		if(ls==0)
		{
			
			cout<<1;
			return 0;
			
		}
		
		cout<<0;
		return 0;
		
	}
	
	return 0;
	
}
