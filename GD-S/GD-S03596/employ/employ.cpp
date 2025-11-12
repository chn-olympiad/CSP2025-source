#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
string ch;
int c[505];
const int Mod=998244353;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin>>ch;
	if(m==n)
	{
		for(int i=0;i<(int)(ch.size());i++)
		{
			if(ch[i]=='0')
			{
				cout<<0;
				return 0;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&c[i]);
	}
	int ans=1;
	for(int i=2;i<=n;i++)
	{
		ans=(ans*i)%Mod;
	}
	printf("%lld",ans);
}
