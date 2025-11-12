#include<iostream>
#include<cstdio> 
using namespace std;
const int mod=998244353;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int ans=1;
	for(int i=1;i<=n;i++)
	{
		ans=(ans*(i%mod))%mod;
	}
	cout<<ans%mod;
	return 0;
}
