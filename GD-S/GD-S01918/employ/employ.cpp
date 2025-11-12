#include <bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,ans=1;
int main()
{
	ifstream cin("employ.in");
	ofstream cout("employ.out");
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		ans*=i;
		ans%=mod;
	}
	cout<<ans;
	return 0;
}
