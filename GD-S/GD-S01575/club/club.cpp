#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
const ll MAXN=1e6+5;
const ll inf=LONG_LONG_MAX;
vector<ll>sum[5];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	ll T;
	cin>>T;
	while(T--)
	{
		ll n,ans=0;
		sum[1].clear();
		sum[2].clear();
		sum[3].clear();
		cin>>n;
		for(register int i=1;i<=n;i++)
		{
			ll a,b,c,t;
			cin>>a>>b>>c;
			t=max(a,max(b,c));
			if((a==t)+(b==t)+(c==t)==1)
			{
				if(a==t)
				{
					sum[1].push_back(a-max(b,c));
				}
				if(b==t)
				{
					sum[2].push_back(b-max(a,c));
				}
				if(c==t)
				{
					sum[3].push_back(c-max(a,b));
				}
			}
			ans+=t;
		}
		for(register int i=1;i<=3;i++)
		{
			if(sum[i].size()>n/2)
			{
				sort(sum[i].begin(),sum[i].end());
				for(register int j=0;j<(sum[i].size()-(n/2));j++)
				{
					ans-=sum[i][j];
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
