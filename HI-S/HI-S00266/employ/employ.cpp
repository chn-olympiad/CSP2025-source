#include<bits/stdc++.h>
using namespace std;
long long k1=1;
long long k2=1;
long long k3=1;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=n-m;i<=n;i++)\
	{
		k1=k1*i;
		k2=k2*i;
		k3=k3*i;
		if(k1%998==0)
			k1=k1/998;
		if(k2%244==0)
			k2=k2/244;
		if(k1%244==0)
			k3=k3/244;
	}
	if(k1>=0)
	{
		cout<<k1;
		return 0;
	}
	if(k2>=0)
	{
		cout<<k2;
		return 0;
	}
	if(k3>=0)
	{
		cout<<k3;
		return 0;
	}
	return 0;
}
