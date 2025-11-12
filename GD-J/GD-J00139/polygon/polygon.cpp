#include <iostream>
#include <cstdio>
using namespace std;

 int n,ans=0,mmax=0,sum=0;
 int a[5002];
 int main()
 {
 	freopen("polygon.in","r",stdin);    freopen("polygon.out","w",stdout);
 	cin>>n;
 	for(int i=1;i<=n;i++)
 		scanf("%d",&a[i]);
 	for(int i=1;i<=n;i++)
 	{
 		if(a[i]>mmax)
 			mmax=a[i];
	}
	for(int i=1;i<=n;i++)
		sum+=a[i];
	if(n>=3)
	{
		if(2*mmax<sum)
			ans=1;
	}
	cout<<ans;
 	return 0;
 }
