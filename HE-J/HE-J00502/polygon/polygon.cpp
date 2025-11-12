#include<bits/stdc++.h>
using namespace std;
long long a[5000];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	long long  maxn=-99999,sum=0,sum1=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
		maxn=max(maxn,a[i]);
	}
	for(int i=1;i<=n-3;i++)
	{
		if(sum>a[i]*2)
		{
			sum1+=n*(n-1)/2;
		}
	}
	cout<<sum-3*2<<endl;
	return 0;
}
