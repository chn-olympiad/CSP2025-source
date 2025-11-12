#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node{
	int val,to,id;
	bool operator <(const node &Y) const{
		return val<Y.val;
	}
};
struct node2{
	int val;
	bool operator <(const node2 &Y) const{
		return val<Y.val;
	}
};
priority_queue<node2> q[5];
int a[N][5],cnt[5],test[N],vis[N],n,ans=0;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		ans=0;
		cnt[2]=0;cnt[3]=0;cnt[1]=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i][1]>=a[i][2] and a[i][1]>=a[i][3])
			{
				q[1].push({max(a[i][2]-a[i][1],a[i][3]-a[i][1])});
				cnt[1]++;
				ans+=a[i][1];
			}
			else if(a[i][2]>=a[i][1] and a[i][2]>=a[i][3])	
			{
				q[2].push({max(a[i][3]-a[i][2],a[i][1]-a[i][2])});
				cnt[2]++;
				ans+=a[i][2];
			}
			else
			{
				q[3].push({max(a[i][2]-a[i][3],a[i][1]-a[i][3])});
				cnt[3]++;
				ans+=a[i][3];
			}	
		}
		while(cnt[1]>n/2)
		{
			cnt[1]--;
			ans+=q[1].top().val;
			q[1].pop();
		}
		while(cnt[2]>n/2)
		{
			cnt[2]--;
			ans+=q[2].top().val;
			q[2].pop();
		}
		while(cnt[3]>n/2)
		{
			cnt[3]--;
			ans+=q[3].top().val;
			q[3].pop();
		}
		while(!q[1].empty())
			q[1].pop();
		while(!q[2].empty())
			q[2].pop();
		while(!q[3].empty())
			q[3].pop();
		cout<<ans<<"\n";
	}
	return 0;
}
