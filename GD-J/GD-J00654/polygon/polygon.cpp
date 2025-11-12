#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long n,a[5005],sum,ma;
int main()
{
	freopen("polygon.in",r,stdin);
	freopen("polygon.out",w,stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
		ma=max(ma,a[i]);
	}
	if(sum>ma*2)cout<<1;
	else cout<<0;

	return 0;	
} 
