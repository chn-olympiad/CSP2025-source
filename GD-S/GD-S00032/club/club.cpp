#include<bits/stdc++.h>
#define fre(s) freopen(#s".in","r",stdin);freopen(#s".out","w",stdout);
using ll=long long;
using namespace std;
const int N=1e5+5;
int T;
int n,a[N][3];
void work()
{
	cin>>n;
	priority_queue<array<int,3>>q[3];
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		int mx=0;
		for(int j=0;j<3;j++)
		{
			cin>>a[i][j];
			if(a[i][j]>a[i][mx])mx=j;
		}
		int diff=1e9,at=0,at1=0;
		for(int j=0;j<3;j++)
		{
			if(j!=mx&&a[i][mx]-a[i][j]<diff)
			diff=min(diff,a[i][mx]-a[i][j]),at=j;
		}
		for(int j=0;j<3;j++)if(j!=at&&j!=mx)at1=j;
		if(q[mx].size()==n/2)
		{
			if(q[mx].top()[0]+diff>0)
			{
				auto [s,x,pre]=q[mx].top();
				ans+=s+a[i][mx];
				q[mx].pop();
				q[mx].push({-diff,i,at});
				for(int j=0;j<3;j++)
				{
					if(a[x][j]<a[x][pre])
					{
						q[j].push({a[x][j]-a[x][pre],x,j});
						break;
					}
				}
			}
			else
			{
				ans+=a[i][at];
				q[at].push({a[i][at1]-a[i][at],i,at1});
			}
		}
		else
		{
			ans+=a[i][mx];
			q[mx].push({-diff,i,at});
		}
	}
	for(int i=0;i<3;i++)
		while(q[i].size())q[i].pop();
	printf("%lld\n",ans);
}
int main()
{
	fre(club);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>T;
	while(T--)work();
}
