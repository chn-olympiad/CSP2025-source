#include<bits/stdc++.h>
using namespace std;
int n,a[4][100005];
long long ans=0;
void solve()
{
	cin>>n;
	ans=0;
	priority_queue<int> q[4];
	for(int i=1;i<=n;i++)
	{
		int to=1;
		for(int j=1;j<=3;j++)
		{
			cin>>a[j][i];
			if(a[to][i]<a[j][i])to=j;
		}
		ans+=a[to][i];
		int g=0;
		for(int j=1;j<=3;j++)
		{
			if(j==to)continue;
			g=max(g,a[j][i]);
		}
		q[to].push(g-a[to][i]);
	}
	for(int j=1;j<=3;j++)
	{
		while(q[j].size()>(n>>1))
		{
			ans+=q[j].top();
			q[j].pop();
		}
	}
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin>>T;while(T--)solve();
	return 0;
}
