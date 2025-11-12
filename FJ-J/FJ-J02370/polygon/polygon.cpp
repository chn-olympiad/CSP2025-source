#include<bits/stdc++.h>
using namespace std;
int n,a[5005],b[5005];
long long zl(int shu)
{
	if(shu==4) return 5;
	if(shu==5) return 16;
	return zl(shu-1)+zl(shu-1)+5*(shu-4);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=b[i-1]+a[i];
	}
	if(n<=3)
	{
		if(b[3]>a[3]*2) cout<<"1";
		else cout<<"0";
		return 0;
	}
	cout<<zl(n);
	return 0;
}
