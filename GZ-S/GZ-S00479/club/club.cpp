//GZ-S00479 观山湖区铭苑中学 陈芷妍
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define pb push_back
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll ans=0;
		for(ll i=1;i<=n;i++)
		{
			ll a,b,c;
			cin>>a>>b>>c;
			ans+=max(a,max(b,c));
		}
		cout<<ans<<endl;
	}
	return 0;
}
