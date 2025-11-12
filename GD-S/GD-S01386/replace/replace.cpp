#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
typedef long long ll;
string S[N][2];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	ll n,q;
	cin>>n>>q;
	for(ll i=1;i<=n;i++)cin>>S[i][0]>>S[i][1];
	while(q--)
	{
		ll ans=0;
		string s,t;
		cin>>s>>t;
		for(ll k=1;k<=n;k++)
		{
			for(ll i=0;i+S[k][0].size()-1<s.size();i++)
			{
				if(s[i]==S[k][0][0])
				{
					int j=i+S[k][0].size()-1;
					if(s.substr(i,j-i+1)==S[k][0])
					{
						string now=s.substr(0,i)+S[k][1]+s.substr(i+S[k][0].size());
						if(now==t){ans++;break;}
					}
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
