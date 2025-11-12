#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll n,m,ans;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	ll c[n];
	cin>>s;
	for(ll i=0;i<n;i++)
	{
		cin>>c[i];
	}
	for(ll i=0;i<n;i++)
	{
		if(s[i]=='1')
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
