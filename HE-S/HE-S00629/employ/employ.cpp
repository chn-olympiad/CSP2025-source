#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m;
string a;
int c[100009];
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	int o=0;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(c[i]==0) o++;
	}
	int ans=1;
	for(int i=0;i<n;i++)
	{
		ans=(ans*(n-i))%mod;
	}
	cout<<ans%mod;
	return 0;
}
