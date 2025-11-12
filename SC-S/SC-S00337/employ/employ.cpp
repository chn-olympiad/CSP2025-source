#include<bits/stdc++.h>
#define int long long 

using namespace std;

const int N=1e6+100,mod=998244353;

int n,m;
int fac[N];

signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	fac[0]=1;
	for(int i=1;i<=n;i++)	fac[i]=fac[i-1]*i%mod;
	cout<<fac[n]<<endl;
	return 0;
}