#include<bits/stdc++.h> 
using namespace std;
int n,g,l,r,number,C,k; 
int a[100010],b[10010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int d=1,a1,a0;
	if(k==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=1)
			{
				d=0;
				break;
			}
		}
		if(d==1)
		{
			cout<<n/2;
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
	}
	a1=0,a0=0,d=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=1&&a[i]!=0)
		{
			d=0;
			break;
		}
		if(a[i]==1)
		{
			a1++;
		}
		else
		{
			a0++;
		}
	}
	if(d==1)
	{
		
		if(k==0)
		{
			cout<<a0+(a1/2);
		}
		else
		{
			cout<<a1;
		}
	}
		
	fclose(stdin);
	fclose(stdout);
	return 0;
}
