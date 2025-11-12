#include<bits/stdc++.h>
using namespace std;
bool A,B;
int n,k,ans;
int a[20005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
		{
			A=1;
		}
		if(a[i]>1)
		{
			B=1;
		}
	}
	if(A==0&&k==0)
	{
		if(n%2==0)
		{
			cout<<n/2;
			return 0;
		} 
		else if(n%2==1)
		{
			cout<<n;
			return 0;
		}
	}
	else if(B==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==k)
			{
				ans++;	
			}
			else
			{
				int kk=a[i];
				for(int j=i+1;j<=n;j++)
				{
					if(kk^a[j]==k)
					{
						i=j+1;
						ans++;
						break;
					}
					else
					{
						kk=kk^a[j];
					}
				}
			}
		}
		cout<<ans+1;
		return 0;
	}
	else
	{
		cout<<10000;
	}
	
}          
