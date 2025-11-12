#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
struct nd
{
int x;bool y;
}a[505];
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,s=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		char x;
		cin>>x;
		s+=(x=='0');
	}
	for(int i=1;i<=n;i++) cin>>a[i].x;
	int l=1;
	for(int i=1;i<=s;i++)
	{
		l=l*i;
		l%=mod;
	}
	for(int i=1;i<=n-s;i++)
	{
		l=l*i;
		l%=mod;
	}
	cout<<l;
}
