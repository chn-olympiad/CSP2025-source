#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
long long ans,mod=998244353;
string s;
int a[10001];
bool f[10001];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
		cin>>a[i];

	ans=1;
	for(int i=n;i>=1;i--)
	{
		ans*=i;
		ans%=mod;
	}
	cout<<ans;
	
	return 0;
}
