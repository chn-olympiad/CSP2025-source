#include <bits/stdc++.h>
using namespace std;
const int Nmax=5e2+7;
const int mod=998244353;
long long ans=1;
int a[Nmax];
int n,m;
string s;
int main()
{
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=n;i>=m;i--)
	{
		ans*=i;
		ans%=mod;
	}
	cout<<ans<<endl;
	return 0;
}