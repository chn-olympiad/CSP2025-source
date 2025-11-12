#include<bits/stdc++.h>

namespace LHY
{

using namespace std;

#define rep(i,s,t) for(int i=s;i<=t;++i)
#define per(i,t,s) for(int i=t;i>=s;--i)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mtp make_tuple
#define fi first
#define se second
#define debug cerr<<"now is:"<<__FUNCTION__<<" on line "<<__LINE__<<'\n'

using LL = long long;
using LD = long double;
using pii = pair<int,int>;
using tiii = tuple<int,int,int>;
using vi = vector<int>;

const int N=800010;

int n;

pii arr[N][5];

int cnt[110];

priority_queue<int,vector<int>,greater<int> > pq[110];

void solve()
{
	cin>>n;
	LL ans=0;
	
	rep(i,0,5)
	{
		while(!pq[i].empty()) pq[i].pop();
		cnt[i]=0;
	}
	
	rep(i,0,n+5)
	{
		rep(j,0,2)
		{
			arr[i][j].fi=arr[i][j].se=0;
		}
	}
	
	rep(i,1,n)
	{
		rep(j,0,2)
		{
			cin>>arr[i][j].fi;
			arr[i][j].se=j;
		}
		sort(arr[i],arr[i]+3,greater<pii>());
		pq[arr[i][0].se].push(arr[i][0].fi-arr[i][1].fi);
		++cnt[arr[i][0].se];
		ans+=arr[i][0].fi;
	}
	rep(i,0,2)
	{
		while(cnt[i]>n/2)
		{
			ans-=pq[i].top();
			pq[i].pop();
			--cnt[i];
		}
	}
	cout<<ans<<'\n';
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	ios::sync_with_stdio(false),cin.tie(nullptr);
	
	int T;cin>>T;
	while(T--)
	{
		solve();
	}
	
	return 0;
}

}

int main()
{
	return LHY::main();
}
