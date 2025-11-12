#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,ans[505],s0=0,c0=0;
int c[505];
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(c[i]==0)c0++;
	}
	sort(c+1,c+1+n);
	for(int i=0;i<(int)s.size();i++)
	{
		if(s[i]=='0')s0++;
	}
	if((n-c0)-max(s0-c0,0)<m)cout<<0;
	else if(s0==0)
	{
		long long tmp=1;
		for(int i=1;i<=n;i++)tmp=(tmp*i)%mod;
		cout<<tmp;
	}
	return 0;
}
