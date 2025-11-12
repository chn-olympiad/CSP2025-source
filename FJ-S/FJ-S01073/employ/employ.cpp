#include<bits/stdc++.h>
#define N 510
#define ll long long
#define mod 998244353
using namespace std;
int n,m;
int f=1;
int c[N];
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]-'0'!=1)
		{
			f=0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	if(f)
	{
		int ls=0,tot=0;
		ll ans=1;
		sort(c+1,c+n+1);
		for(int i=1;i<=n;i++)
		{
			tot++;
			if(c[i]<tot)
			{
				ans=(ans*(((ls-1)*ls)>>1))%mod;
				ls=1;
			}
			else
			{
				ls++;
			}
		}
		cout<<ans;
		return 0;
	}
	cout<<0;
}
