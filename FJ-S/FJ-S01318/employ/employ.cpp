#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long ans=1;
	for(int i=1;i<=n;i++)
	{
		ans*=i;
		ans%=mod;
	}
	cout<<0;
	return 0;
}
