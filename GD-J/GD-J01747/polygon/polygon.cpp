#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],p;
long long fywy(long long x,long long y)
{
	long long sum=0,ans=0;
	for(int z=x;z>=1;z--)
	{
		sum=0;
		for(int i=z;i>=1;i--)
		{
			sum+=a[i];
			if(sum>y)
			{
				ans=ans+1+i*(i-1)/2;
				sum-=a[i];
			}
			if(sum==y)
			{
				ans=ans+i*(i-1)/2;
				sum-=a[i];
			}
		}
	}
	
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++)
	{
		p=p+fywy(i-1,a[i]);
	}
	cout<<p;
	return 0;
}
