#include<bits/stdc++.h>
using namespace std;
int a[5097];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,ma=0,jgc;//n!=ni
	long long ni=1;
	long long sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	if(n<3)
	{
		cout<<0;
		return 0;
	}
	if(n==3)
	{
		sort(a+1,a+1+n);
		if(a[1]+a[2]>a[3])
		{
			cout<<1;
			return 0;
		}
		else
		{
			cout<<0;
			return 0;
		}
	}
	else if(ma==1)
	{
//		jgc=n-2;
		for(int i=1;i<=n;i++)
		{
//			ni=(ni+998244353)%998244353;
			ni=(ni*i+998244353)%998244353;
//			cout<<ni<<endl;
			
		}
//		cout<<ni<<endl;
//		cout<<endl;
		for(int i=3;i<=n;i++)
		{
			long long ii=1,ini=1;//i!==ii,(n-i)!=ini;
			long long c;
			for(int j=1;j<=i;j++)
			{
				ii*=j;
				ii=(ii+998244353)%998244353;
//				cout<<ii<<" ";
				
			}
			for(int j=1;j<=n-i;j++)
			{
				ini*=j;
				ini=(ini+998244353)%998244353;
				//cout<<ini<<" ";
				
			}
			
			c=(ni/(ii*ini)+998244353)%998244353;
//			c=ni/(ii*ini);
//			cout<<c<<endl;
			sum+=c;
		}
		cout<<(sum+998244353)%998244353;
//		cout<<sum;
	}
	return 0;
}
