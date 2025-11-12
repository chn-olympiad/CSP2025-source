#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,ans;
int a[505];
//int u[N],m[N],w[N]; 
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	string s;
	scanf("%lld%lld",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ans+=a[i];
	}
	cout<<ans%998244353;
	return 0; 
}
