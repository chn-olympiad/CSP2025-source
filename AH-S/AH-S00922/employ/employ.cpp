#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[600],sum;
const int mod=998244353;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(c[i]==0)	sum++;
		//cout<<sum;
	}
	long long int ans=1;
	//cout<<sum;
	for(int i=1;i<=n;i++)
	{
		ans=ans*i;
		ans=ans%mod;
	}
	cout<<ans%mod;
    return 0;
}

