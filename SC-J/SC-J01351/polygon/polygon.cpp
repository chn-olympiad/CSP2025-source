#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[5050],ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=3;i<=n;i++)
	{
		int maxn=1;
		for(int j=1;j<=i;j++)
			maxn=((n-i+1)%998244353*maxn)%998244353;
		ans=(maxn+ans%998244353)%998244353;
	}
	cout<<ans;
	return 0;
 } 