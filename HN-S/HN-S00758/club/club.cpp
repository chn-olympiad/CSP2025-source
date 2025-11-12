#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int a[N][4],cnt[4];
priority_queue<int>pq[4];
void Main()
{
	int n,ans=0;
	cin>>n;
	int m=n/2;
	memset(a,-1,sizeof 0);
	for(int i=1;i<=3;i++)
	{
		while(!pq[i].empty()) pq[i].pop();
		cnt[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		int k=0,c=0;
		for(int j=1;j<=3;j++)
		{
			cin>>a[i][j];
			if(a[i][j]>=a[i][k])
			{
				c=k;
				k=j;
			}
			else if(a[i][j]>=a[i][c])
				c=j;
		}
		int a1=a[i][k],a2=a[i][c]; 
		if(cnt[k]==m)
		{
			if(pq[k].top()+a1>a2)
			{
				ans+=pq[k].top()+a1;
				pq[k].pop();
				pq[k].push(a2-a1);
			}
			else
			{
				ans+=a2;
				cnt[c]++;
			}
		}
		else
		{
			pq[k].push(a2-a1);
			ans+=a1;
			cnt[k]++;
		}
	}
	cout<<ans<<'\n';
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--) Main();
	return 0;
}
