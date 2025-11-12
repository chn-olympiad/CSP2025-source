#include<bits/stdc++.h>
using namespace std;
priority_queue<pair<int,int> >q[5];
int a[5],len[5];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		memset(len,0,sizeof(len));
		for(int i=1;i<=3;i++)
		{
			while(!q[i].empty()) q[i].pop();
		}
		int n;
		cin>>n;
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			int x,y,z,p;
			cin>>x>>y>>z;
			p=max(max(x,y),z);
			int mxid,nmxid;
			if(p==x)
			{
				mxid=1;
				if(max(y,z)==y)
				{
					nmxid=2;
				}
				else nmxid=3;
			}
			else if(p==y)
			{
				mxid=2;
				if(max(x,z)==x)
				{
					nmxid=1;
				}
				else nmxid=3;
			}
			else
			{
				mxid=3;
				if(max(x,y)==x)
				{
					nmxid=1;
				}
				else nmxid=2;
			}
			a[1]=x;
			a[2]=y;
			a[3]=z;
			if(len[mxid]==n/2)
			{
				if(a[nmxid]-a[mxid]<q[mxid].top().first)
				{
					int p1=q[mxid].top().first,p2=q[mxid].top().second;
					q[mxid].pop();
					ans+=p1;
					len[p2]++;
					ans+=a[mxid];
					q[mxid].push({a[nmxid]-a[mxid],nmxid});
				}
				else
				{
					ans+=a[nmxid];
					len[nmxid]++;
				}
			}
			else
			{
				ans+=a[mxid];
				q[mxid].push({a[nmxid]-a[mxid],nmxid});
				len[mxid]++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
