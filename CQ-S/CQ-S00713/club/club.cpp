#include <bits/stdc++.h>
using namespace std;
#define lowbit(x) (x&-x)
#define endl '\n'

namespace satsujinki{
const int maxn=1e5+10;
int t,n,a[maxn][3];
priority_queue<int,vector<int>,greater<int>>pq;
int zt[maxn];

void MAIN()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		int cnt[3],sum=0;
		cnt[0]=0;
		cnt[1]=0;
		cnt[2]=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			int maxx=max(max(a[i][0],a[i][1]),a[i][2]);
			sum+=maxx;
			if(maxx==a[i][0])
			{
				cnt[0]++;
				zt[i]=0;
			}
			else if(maxx==a[i][1])
			{
				cnt[1]++;
				zt[i]=1;
			}
			else if(maxx==a[i][2])
			{
				cnt[2]++;
				zt[i]=2;
			}
		}
		int id=-1;
		if(cnt[0]+cnt[0]>n)
		{
			id=0;
		}
		if(cnt[1]+cnt[1]>n)
		{
			id=1;
		}
		if(cnt[2]+cnt[2]>n)
		{
			id=2;
		}
		if(id==-1)
		{
			cout<<sum<<endl;
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				swap(a[i][0],a[i][id]);
				if(zt[i]==id)
				{
					pq.push(a[i][0]-max(a[i][1],a[i][2]));
				}
			}
			while(cnt[id]+cnt[id]>n)
			{
				cnt[id]--;
				sum-=pq.top();
				pq.pop();
			}
			while(pq.size())
			{
				pq.pop();
			}
			cout<<sum<<endl;
		}
	}
}
}

signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	satsujinki::MAIN();
//while(1);
	return 0;
}
/*
time:1.0 S
memory:512 MiB
real:4MB


*/
