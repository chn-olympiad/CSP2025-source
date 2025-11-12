#include <bits/stdc++.h>
using namespace std;
long long n,a[10000],num[10000],qzh[10000],ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		num[a[i]]++;
		qzh[i]=qzh[i-1]+a[i];
	}
	if(num[1]==n)
	{
		for(int i=n-2;i>=1;i--) ans+=i;
		cout<<ans;
		return 0;
	}
	cout<<0;
	return 0;
} 
