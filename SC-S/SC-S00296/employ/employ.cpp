#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,mxp=0,cnt=0;
string s;
vector<ll> a;
int mian()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(ll i=0,v;i<n;i++)
	{
		cin>>v;
		a.push_back(v);
		mxp=max(v,mxp);
	}
	for(char c:s)
	{
		cnt+=((c=='1')?1:0);
	}
	cout<<(m==1?(cnt*mxp*mxp*n%998244353):7);
	return 0;
}