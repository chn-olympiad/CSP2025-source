#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
ll T,n,ans,a[N][4],p[N],cnt[4];
priority_queue <ll> q;
void Solve()
{
	ans=cnt[1]=cnt[2]=cnt[3]=0;
	while(q.size()) q.pop();
	for(int i=1;i<=n;i++)
	{
		p[i]=0;
		for(int j=1;j<=3;j++)
		{
			a[i][j]=0;
		}
	}
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
		{
			cin>>a[i][j];
		}
		p[i]=1;
		if(a[i][2]>a[i][p[i]]) p[i]=2;
		if(a[i][3]>a[i][p[i]]) p[i]=3;
		cnt[p[i]]++;
		ans+=a[i][p[i]];
	}
	int v=1;
	if(cnt[2]>cnt[v]) v=2;
	if(cnt[3]>cnt[v]) v=3;
	ll sum=max(0ll,cnt[v]-n/2);
	for(int i=1;i<=n;i++)
	{
		if(p[i]==v)
		{
			ll w=0;
			for(int j=1;j<=3;j++)
			{
				if(j!=p[i]) w=max(a[i][j],w);
			}
			w-=a[i][p[i]];
			q.push(w);
		}
	}
	while(sum--)
	{
		ans+=q.top();
		q.pop();
	}
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--) Solve();
	return 0;
}
