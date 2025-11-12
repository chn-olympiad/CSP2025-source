#include<bits/stdc++.h>
using namespace std;
struct node
{
	pair<int,int> x,y,z;
	bool operator < (const node &o)const
	{
		return x.first+o.y.first!=o.x.first+y.first?x.first+o.y.first>o.x.first+y.first:x.first+o.z.first>o.x.first+z.first;
	}
};
int T,n,sum[5];
pair<int,int> k[5];
node u[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		for(int i=1;i<=n;i++)
			u[i].x={0,0},u[i].y={0,0},u[i].z={0,0};
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			k[1].second=1,k[2].second=2,k[3].second=3;
			cin>>k[1].first>>k[2].first>>k[3].first;
			stable_sort(k+1,k+4);
			u[i].x=k[3],u[i].y=k[2],u[i].z=k[1];
		}
		stable_sort(u+1,u+n+1);
		sum[1]=sum[2]=sum[3]=0;
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(sum[u[i].x.second]>=n/2)
			{
				if(sum[u[i].y.second]>=n/2)
					sum[u[i].z.second]++,ans+=u[i].z.first;
				else
					sum[u[i].y.second]++,ans+=u[i].y.first;
			}
			else
				sum[u[i].x.second]++,ans+=u[i].x.first;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
