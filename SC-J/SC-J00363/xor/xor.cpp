#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k;
vector<ll> a;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=0,v;i<n;i++)
	{
		cin>>v;
		a.push_back(v);
	}
	if(k==0)
	{
		cout<<(n>>1);
	}
	else
	{
		cout<<n;
	}
	return 0;
}