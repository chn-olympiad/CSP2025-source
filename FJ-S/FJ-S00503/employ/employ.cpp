#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[502];
long long a[502];
long long ans=1;
long long mod=998244353;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s+1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		ans=ans*i%mod;
	}
	cout<<ans;
}
