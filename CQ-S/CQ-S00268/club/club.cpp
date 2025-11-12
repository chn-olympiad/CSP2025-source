#include<bits/stdc++.h>
#define ll long long
#define db double
#define int ll//#
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int inf=2e9;
const db eps=1e-7;
int n,a[100005][5],num[5];
vector<int>c[5];
void init()
{
	memset(a,0,sizeof(a));
	memset(num,0,sizeof(num));
	for(int i=1;i<=3;i++)c[i].clear();
}
void solve()
{
	init();
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
		{
			ans+=a[i][1];
			num[1]++;
			c[1].pb(min(a[i][1]-a[i][2],a[i][1]-a[i][3]));
		}
		else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])
		{
			ans+=a[i][2];
			num[2]++;
			c[2].pb(min(a[i][2]-a[i][1],a[i][2]-a[i][3]));
		}
		else
		{
			ans+=a[i][3];
			num[3]++;
			c[3].pb(min(a[i][3]-a[i][2],a[i][3]-a[i][1]));
		}
	}
	for(int i=1;i<=3;i++)
	{
		if(num[i]>n/2)
		{
			int d=num[i]-n/2;
			sort(all(c[i]));
			for(int j=0;j<d;j++)
			{
				ans-=c[i][j];
			}
			break;
		}
	}
	cout<<ans<<"\n";
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
	return 0;
}

