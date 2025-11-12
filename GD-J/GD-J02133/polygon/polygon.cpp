#include <bits/stdc++.h>
using namespace std;
int n,a[5005],cnt,b[5005],k;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	k=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int x=a[n];
	for(int j=n;j>=1;j--)
	{
		for(int k=1;k<=j;k++)
		{
			if(a[k+1]<a[k])
			{
				swap(a[k],a[k+1]);
			}
		}
	}
	a[n+1]=x;
	for(int i=2;i<=n+1;i++)
	{
		cout<<a[i]<<" ";
	}
	for(int i=2;i<=n+1;i++)
	{
		b[i]=a[i]+b[i-1];
		cout<<b[i]<<" ";
	}
	b[n]=b[n-1]+a[n];
	cout<<endl;
	for(int i=n+1;i>2;i--)
	{
		for(int j=i-1;j>=0;j--)
		{
			if(i==3)
			{
				j=0;
			}
			if(b[i]-a[j] > a[i]*2)
			{
				cnt++;
			}
		}
	}
	cout<<cnt-1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
