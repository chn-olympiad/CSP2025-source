#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[600],b[600];
const int mod=998244353;
long long ans=1;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
    cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	for(int i=1;i<=n;i++)
	{
		ans*=i;
		ans%=mod;
	}
	cout<<ans;
	return 0;
}
