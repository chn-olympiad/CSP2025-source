#include<bits/stdc++.h>
#define rep(i,l,r,k) for(int i=l;i<=r;i+=k)
#define rrep(i,r,l,k) for(int i=r;i>=l;i-=k)
#define loop(i,st,ed,nxt) for(int i=st;i!=ed;i=nxt)
#define int long long
using namespace std;
const int N=1e5+5;
int a[N][4];
pair<int,int>b[4];
void init()
{
	
}
void solve()
{
	priority_queue<int,vector<int>,greater<int> >q[4];
	int n,ans=0;
	cin>>n;
	rep(i,1,n,1)rep(j,1,3,1)cin>>a[i][j];
	rep(i,1,n,1)
	{
		rep(j,1,3,1)b[j]=make_pair(a[i][j],j);
		sort(b+1,b+4);
		
		q[b[3].second].push(b[3].first-b[2].first);
		ans+=b[3].first;
	}
	rep(i,1,3,1)while((int)q[i].size()>n/2)
	{
		ans-=q[i].top();
		q[i].pop();
	}
	cout<<ans<<'\n';
}
signed main()
{
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T=1;
	cin>>T;
	init();
	rep(i,1,T,1)
	{
		solve();
	}
	return 0;
}
