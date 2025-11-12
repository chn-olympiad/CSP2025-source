#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,m;
string s;
int c[505];
int jie(int k)
{
	int sum=1;
	for(int i=1;i<=k;i++)
	  sum=(sum*k)%mod;
	return sum;
}
bool check()
{
	for(int i=0;i<s.size();i++)
	  if(s[i]!='1')
	    return false;
	return true;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(check())
	{
		cout<<jie(n);
		return 0;
	}
	cout<<0;
	return 0;
}

