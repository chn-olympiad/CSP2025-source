#include<bits/stdc++.h>
using namespace std;
int a[5000],n=0,x,num=0,b[5000];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
		cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(a[i]>a[j])
			{
				x=a[i];
				a[i]=a[j];
				a[j]=x;
			}
		}
	}
	b[0]=a[0];
	for(int i=1;i<n;i++)
	{
		b[i]=b[i-1]+a[i];
	}
	

	for(int j=0;j<=n-3;j++)
	{
	
	for(int i=2;i<n;i++)
	{
		if(i-3-j>=0)
		{
		
		if(2*a[i]<b[i]-b[i-3-j])
		{
			num++;
		}
		}
		else if(b[i]>2*a[i])
		{
			num++;
		}
	}
}
	cout<<num;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
