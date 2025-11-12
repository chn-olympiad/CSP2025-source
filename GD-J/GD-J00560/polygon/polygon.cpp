#include<bits/stdc++.h>
using namespace std;
int f[5005],n,a[5005],b[5005],t;
void count(int k,int x,int sum)
{
	if(k==0)
	{
		if(sum>x)
		{
			t++;
			return;
		}
		else
		{
			return;
		}
	}
	count(k-1,x,sum);
	count(k-1,x,sum+a[k-1]);	
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		b[i]=b[i-1]+a[i];
	}
	f[0]=f[1]=0;
	for(int i=2;i<n;i++)
	{
		if(b[i-1]<=a[i])
		{
			f[i]=f[i-1];
		}
		else
		{
			count(i,a[i],0);
			f[i]=(f[i-1]+t)%998244353;
			t=0;
		}
	}
	cout<<f[n-1];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
