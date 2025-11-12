#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e2+5;
const int MOD=998244353;
int n,m,c[N];
string a;
int ans=1;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	for(int i=1;i<=n;i++)
	{
		ans*=i;
		ans%=MOD;
	}
	cout<<(ans%MOD);
	return 0;
}
