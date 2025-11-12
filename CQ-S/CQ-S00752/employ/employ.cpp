#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int n,m;
long long p=1;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		int a;
		cin>>a;
		p=p*(long long)i%mod;
	}
	printf("%lld",p);
	return 0;
}
