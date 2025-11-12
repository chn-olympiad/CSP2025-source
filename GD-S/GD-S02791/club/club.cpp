#include<bits/stdc++.h>
#define ll long long
#define PII pair<long long,long long>
#define f first
#define s second
using namespace std;
ll T,n,ans,k;
ll a[100101][4];
int vis[100101];
int max(int x,int y)
{
	if(x>y)
		return x;
	return y;
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		priority_queue<PII,vector<PII>,less<PII> >q1;
		priority_queue<PII,vector<PII>,less<PII> >q2;
		priority_queue<PII,vector<PII>,less<PII> >q3;
		cin>>n;
		ll sum[4];
		sum[1]=0,sum[2]=0,sum[3]=0;
		k=n/2;
		ans=0;
		for(ll i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			ll mmx=max(a[i][1],max(a[i][2],a[i][3]));
			if(mmx==a[i][1])
			{
				vis[i]=1;
				ans+=a[i][1];
				sum[1]++;
				q1.push({a[i][2]-a[i][1],i});
				q1.push({a[i][3]-a[i][1],i});
			}
			else if(mmx==a[i][2])
			{
				vis[i]=2;
				ans+=a[i][2];
				sum[2]++;
				q2.push({a[i][1]-a[i][2],i});
				q2.push({a[i][3]-a[i][2],i});
			}
			else
			{
				vis[i]=3;
				ans+=a[i][3];
				sum[3]++;
				q3.push({a[i][2]-a[i][3],i});
				q3.push({a[i][1]-a[i][3],i});
			}
		}
		ll mmax=max(sum[3],max(sum[1],sum[2]));
		if(mmax>k)
		{
			if(mmax==sum[1])
			{
				while(1)
				{
					if(sum[1]<=k)
					{
						break;
					}
					int u=q1.top().f,v=q1.top().s;
					if(vis[v]==1)
					{
						ans=ans+u;
						vis[v]=0;
						sum[1]--;
					}
					q1.pop();
				}
			}
			else if(mmax==sum[2])
			{
				while(1)
				{
					if(sum[2]<=k)
					{
						break;
					}
					int u=q2.top().f,v=q2.top().s;
					if(vis[v]==2)
					{
						ans=ans+u;
						vis[v]=0;
						sum[2]--;
					}
					q2.pop();
				}
			}
			else
			{
				while(1)
				{
					if(sum[3]<=k)
					{
						break;
					}
					int u=q3.top().f,v=q3.top().s;
					if(vis[v]==3)
					{
						ans=ans+u;
						vis[v]=0;
						sum[3]--;
					}
					q3.pop();
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
