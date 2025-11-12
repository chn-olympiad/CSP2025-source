#include<bits/stdc++.h>
using namespace std;
long long ans,n,m,t,mod=998244353,c[510];
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
	if(s[i-1]=='1')t++;
	for(int i=1;i<=n;i++)
	  cin>>c[i];
	if(t<m)
	  cout<<0;
	else 
	{
		ans=1;
		for(int i=1;i<=n;i++)
		  ans=ans*n%mod;
		cout<<ans;
	}
	return 0;
}
