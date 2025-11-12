#include <bits/stdc++.h>
using namespace std;
int a[100005]={0};

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	if(k==0)
	{
		bool flag1=true;
		bool flag2=true;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]!=1)
			{
				flag1=false;
			}
			if(a[i]!=0&&a[i]!=1)
			{
				flag2=false;
			}
		}
		if(flag1==true)
		{
			if(n%2==0)
			{
				cout<<n;
				
			}
			else
			{
				cout<<n-1;
			}
		}
		else if(flag2==true)
		{
			int cnt=0;
			int x;
			int y;
			for(int i=1;i<=n;i++)
			{
				if(a[i]==1)
				{
					cnt++;
						
					if(cnt==2)
					{
						x=i;
					}
				
				}
				
			}
			int z=0;
			for(int i=n;i>=1;i--)
			{
				if(a[i]==1)
				{
					z++;
					if(z==2)
					{
						y=i;
						break;
					}
				}
				
			}
			if(cnt%2==0)
			{
				cout<<n;
				
			}
			else
			{
				cout<<max(y,n-x);
				
			}
		}
		
	}
	else
	{
		cout<<n-1;
	}
	return 0;
}
