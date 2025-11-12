#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int T,n,a[N][5],ans,len[5],li,vis[N];
struct zz
{
	int val,x,y;
	bool operator < (const zz&other) const
	{
		return val<other.val;
	}
};
priority_queue<zz>q;
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--)
	{
		while(!q.empty())q.pop();
		cin>>n,ans=0,li=n/2;
		memset(len,0,sizeof(len));
		for(int i=1;i<=n;i++)
		{
			vis[i]=0;
			for(int j=1;j<=3;j++)cin>>a[i][j],q.push({a[i][j],i,j});
		}
		while(!q.empty())
		{
			while(q.size()&&vis[q.top().x])q.pop();
			if(q.size())
			{
				vis[q.top().x]=q.top().y;
				len[q.top().y]++;
				ans+=q.top().val;
				q.pop();
			}
		}
		if(len[1]<=li&&len[2]<=li&&len[3]<=li)cout<<ans<<endl;
		else
		{
			int o=0;
			for(int i=1;i<=3;i++)if(len[i]>li)o=i;
			while(!q.empty())q.pop();
			for(int i=1;i<=n;i++)
			{ 
				if(vis[i]==o)
				{
					for(int j=1;j<=3;j++)
					{
						if(j==o)continue;
						q.push({a[i][j]-a[i][o],i,0});
					}
				}
				vis[i]=0;
			}
			while(q.size()&&len[o]>li)
			{
				while(q.size()&&vis[q.top().x])q.pop();
				if(q.size())
				{
					ans+=q.top().val;
					vis[q.top().x]=1;
					q.pop();
					len[o]--;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
