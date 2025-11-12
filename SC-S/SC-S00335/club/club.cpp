#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int a[N][5];
int cnt[5];
int xz[N];
struct node
{
	int x,id;
	bool operator <(const node &a) const
	{
		return x<a.x;
	}
};
priority_queue <node> q1,q2,q3;
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--)
	{
		memset(xz,0,sizeof xz);
		memset(cnt,0,sizeof cnt);
		int n;
		cin>>n;
		int sx=n/2;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		int ans=0;
		int d=0;
		int lst=0;
		for(int i=1;i<=n;i++)
		{
			lst=i;
			if(a[i][1]>a[i][2]&&a[i][1]>a[i][3]) cnt[1]++,ans+=a[i][1],xz[i]=1;
			else if(a[i][2]>a[i][3]) cnt[2]++,ans+=a[i][2],xz[i]=2;
			else cnt[3]++,ans+=a[i][3],xz[i]=3;
			if(cnt[1]==sx)
			{
				d=1;
				break;
			}
			else if(cnt[2]==sx) 
			{
				d=2;
				break;
			}
			else if(cnt[3]==sx)
			{
				d=3;
				break;
			}
		}
		int qt1,qt2;
		if(d==1) qt1=2,qt2=3;
		if(d==2) qt1=1,qt2=3;
		if(d==3) qt1=1,qt2=2;
		if(d==0)
		{
			cout<<ans<<'\n';
			continue;
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				if(xz[i]==d)
				{
					q1.push({max(a[i][qt1],a[i][qt2])-a[i][d],i});
				}
				else 
				{
					q2.push({a[i][d],i});
					q3.push({max(a[i][qt1],a[i][qt2]),i});
				}
			}
		}
		for(int i=lst+1;i<=n;i++)
		{
			while(!q2.empty()&&xz[q2.top().id]!=0) q2.pop();
			while(!q3.empty()&&xz[q3.top().id]!=0) q3.pop();
			int xx=q3.top().x;
			if(xx>q1.top().x+q2.top().x) 
			{
				ans+=xx;
				xz[q3.top().id]=4;
				q3.pop();
			}
			else
			{
				ans+=q1.top().x+q2.top().x;
				xz[q1.top().id]=4;
				xz[q2.top().id]=d;
				q1.pop();
				q1.push({max(a[q2.top().id][qt1],a[q2.top().id][qt2])-a[q2.top().id][d],q2.top().id});
				q2.pop();
			}
		}
		cout<<ans<<'\n';
		while(!q1.empty()) q1.pop();
		while(!q2.empty()) q2.pop();
		while(!q3.empty()) q3.pop();
	}
	return 0; 
}