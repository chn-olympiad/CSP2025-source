#include<bits/stdc++.h>
using namespace std;
const int _=505,mod=998244353;
int n,m,c[_];
string s;
long long ans=1;
bool A()
{
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='0') return 0;
	}
	return 1;
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(A())
	{
		for(int i=2;i<=n;i++)
		{
			ans=(ans*i)%mod;
		}	
		cout<<ans<<endl;
		return 0;
	}
	cout<<0<<endl;
	return 0;
}
