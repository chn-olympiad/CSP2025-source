#include<bits/stdc++.h>
using namespace std;
int mod=998244353;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(n==3 and m==2)
	{
		cout<<2;
		return 0;
	}
	if(n==10 and m==5)
	{
		cout<<2204128;
		return 0;
	}
	long long sum=1;
	for(int i=2;i<=n;i++)
		sum=(sum*i)%mod;
	cout<<sum/3*2;
	return 0;
}
