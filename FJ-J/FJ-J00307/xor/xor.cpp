#include<bits/stdc++.h>
using namespace std;
int n,k,A=1,B=1,a[500005];
int main()
{
    frepoen("xor.in","r",stdin);
    frepoen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
		{
			A=0;
		}	
		else if(a[i]!=1&&a[i]!=0)
		{
			B=0;
		}
	}
	if(A==1)//20
	{
		if(k==1)
		{
			cout<<n;
			return 0;
		} 
		else if(k==0)
		{
			cout<<n/2;
			return 0;
		} 
		else 
		{
			cout<<n/k;
			return 0;
		}
	}
	if(B==1)//30
	{
		int ans=0;
		if(k==0)
		{
			int i=1;
			while(i<=n)
			{
				if(a[i]==0)
				{
					ans++;
					i++;
				}
				else if(a[i]==a[i+1]&&i+1<=n)
				{
					ans++;
					i+=2;
				}
				else 
				{
					i++;
				}
			}
			cout<<ans;
			return 0;			
		}
		else if(k==1)
		{
			int i=1;
			while(i<=n)
			{
				if(a[i]==1)
				{
					ans++;
					i++;
				}
				else if(a[i]!=a[i+1]&&i+1<=n)
				{
					ans++;
					i+=2;
				}
				else 
				{
					i++;
				}
			}
			cout<<ans;
			return 0;				
		}
	}


	return 0;
}

