#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c[500];
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	ll ans=0;
	for(int i=1;i<n;i++)
	{
		ans+=i*i+1;
		ans%=998244353;
	}
	cout<<ans;
	
}
