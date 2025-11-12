#include<iostream>
using namespace std;
long long n,a[5005],cnt,sum,m;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n==3)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					long long sum=a[i]+a[j]+a[k],m=max(a[i],max(a[j],a[k]));
					if(sum>2*m)cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	for(int i=3;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			sum=0,m=0;
			for(int k=j;k<=n;k++)
			{
				sum+=a[k];
				if(a[k]>m)m=a[k];
			}	
			if(sum>2*m)cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
