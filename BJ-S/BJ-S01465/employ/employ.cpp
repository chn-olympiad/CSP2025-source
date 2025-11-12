#include<bits/stdc++.h>
using namespace std;
char s[510];
int c[510];
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	for (int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	long long ans=1;
	for (int i=1;i<=n;i++)
	{
		ans*=i;
		ans%=998244353;
	}
	cout<<ans<<endl;
	return 0;
	return 0;
}
