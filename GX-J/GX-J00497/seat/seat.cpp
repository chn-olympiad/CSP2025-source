#include<bits/stdc++.h>
using namespace std;
int a[10000];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	printf("%d%d",n,m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
	}
	int sum=a[1];
	for(int i=1;i<=n*m;i++)
	{
		for(int j=n*m;j>1;j--)
		{
			if(a[i]>a[i+1])
			{
				int f=a[i+1];
				a[i+1]=a[i];
				a[i]=f;
			}
			if(a[j]<a[j-1])
			{
				int f=a[j-1];
				a[j-1]=a[j];
				a[j]=f;	
			}
		}
	}
	for(int i=1,j=n*m;i<=n*m;i++,j--)
	{
		if(sum==a[i])
		{
			sum=j;
			break;
		}	
	}
	if(sum<=n)
	{
		cout<<1<<" "<<n;
		return 0;
	}
	if(sum/m%2==1)
	{
		cout<<sum/m+1<<" "<<n+1-sum%n;
	}
	else
	{
		cout<<sum/m+1<<" "<<sum%n;
	}
	return 0;
}
