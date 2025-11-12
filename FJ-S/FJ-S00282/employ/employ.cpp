#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[20];
int p[20],sum=1,flag[20];
int mod=998244353;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		sum*=i;
		sum%=mod;
		cin>>c[i];
	}
	cout<<sum%mod;
	return 0;
}
