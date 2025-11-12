#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505,MOD=998244353;

int n,m;
int c[N];
char s[N];
ll ans;

ll quanpai(int x)
{
	ll res=1;
	for(int i=1;i<=n;i++)
	{
		res=((res%MOD)*(i%MOD))%MOD;
	}
	return res;
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	bool isA=true;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		if(s[i]=='0') isA=false;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	if(isA)
	{
		ans=quanpai(n);
	}
	cout<<ans%MOD<<"\n";
	return 0;
}
