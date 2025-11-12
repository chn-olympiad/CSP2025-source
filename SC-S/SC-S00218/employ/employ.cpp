#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,c[510];
long long ans,sum;
bool flag=1;
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
		if(s[i]!='1')flag=0;
		else sum++;
	}
	if(flag)
	{
		ans=1;
		for(int i=1;i<=n;i++)
		{
			ans*=i;
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	if(m==n)
	{
		cout<<0;
		return 0;
	}
	if(sum<m)
	{
		cout<<0;
		return 0;
	}
	return 0;
}