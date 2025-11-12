#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a1=0,flag=0,a3,a5,a6=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==1)
		{
			a6++;
		}
	}
	if(k==0 && a6==n)
	{
		cout<<n/2;
	}
	else if(k==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1)
			{
				a1++;
			}
		}
		cout<<a1;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==k)
			{
				a[i]=-1;
				a1++;
			}
		}
		for(int i=2;i<=n;i++)
		{
			for(int z=1;z<=n-i+1;z++)
			{
				for(int j=z;j<=j+i-1;j++)
				{
					if(a[j]==-1)
					{
						flag=1;
						break;
					}
					else
					{
						if(j==z)
						{
							a5=a[j];
						}
						a3=max(a5,a[j+1]);
						if(a3>=1 && a3<=3)
						{
							a5=(3-a5)+(3-a[j+1]);
						}
						else if(a3>3 && a3<=7)
						{
							a5=(7-a5)+(7-a[j+1]);
						}
						else if(a3>7 && a3<=15)
						{
							a5=(15-a5)+(15-a[j+1]);
						}
						else if(a3>15 && a3<=31)
						{
							a5=(31-a5)+(31-a[j+1]);
						}
						else if(a3>31 && a3<=63)
						{
							a5=(63-a5)+(63-a[j+1]);
						}
						else if(a3>63 && a3<=127)
						{
							a5=(127-a5)+(127-a[j+1]);
						}
						else if(a3>127 && a3<=255)
						{
							a5=(255-a5)+(255-a[j+1]);
						}
					}
				}
				if(a5==k && flag==0)
				{
					a1++;
				}
				flag=0;
			}
		}
		cout<<a1;
	}
	return 0;
}
