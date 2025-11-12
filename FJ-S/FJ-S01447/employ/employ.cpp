#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long mod=998244353,n,s=1;
	cin>>n;
	for(int i=1;i<=n;i++)
		s=(s*i)%mod;
	cout<<s;
	return 0;
}
