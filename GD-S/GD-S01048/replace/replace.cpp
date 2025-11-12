#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<string,string> mp;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ll n,q;
	scanf("%lld%lld",&n,&q);
	string s1,s2;
	for(ll i=1;i<=n;i++)
	{
		cin>>s1>>s2;
		mp[s1]=s2;
	}
	string x,y,z;
	ll ans;
	while(q--)
	{
		cin>>s1>>s2;
		if(s1.size()!=s2.size())
		{
			printf("0\n");
			continue;
		}
		ans=0;
		for(ll i=0;i<s1.size();i++)
		{
			for(ll j=1;j<=s1.size()-i;j++)
			{
				x=s1.substr(0,i);
				y=s1.substr(i,j);
				z=s1.substr(i+j,s1.size()-i-j);
				if(x+mp[y]+z==s2)
					ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

