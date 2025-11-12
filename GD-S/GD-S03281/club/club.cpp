#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
int t;
int a[N][5];
int cnt[5];
ll dp[N];
int ss[N], d[N];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--)
	{
		memset(ss,0,sizeof(ss));
		memset(d,0,sizeof(d));
		priority_queue<int,vector<int>,greater<int>> pq;
		memset(a,0,sizeof(a));
		memset(dp,0,sizeof(dp));
		memset(cnt,0,sizeof(cnt));
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<3;j++)
			{
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=n;i++)
		{
			d[i]=max(a[i][0],max(a[i][1],a[i][2]));
			int nt;
			if(d[i]==a[i][0])
			{
				nt=0;
				cnt[nt]++;
			}
			else if(d[i]==a[i][1]){
				nt=1;
				cnt[nt]++;
			}
			else{
				nt=2;
				cnt[nt]++;
			}
			ss[i]=nt;
		}
		int c;
		if(cnt[0]>n/2)
		{
			c=0;
		 } 
		 else if(cnt[1]>n/2)
		 {
		 	c=1;
		 }
		 else if(cnt[2]>n/2){
		 	c=2;
		 }
		 else {
		 	c=3;
		 }
		if(c==3)
		{
			for(int i=1;i<=n;i++)
			{
				dp[i]=dp[i-1]+d[i];
			}
			cout<<dp[n]<<"\n";
			continue;
		}
		int minx;
		for(int i=1;i<=n;i++)
		{
			if(ss[i]==c)
			{
				minx=min(d[i]-a[i][(ss[i]+1)%3],d[i]-a[i][(ss[i]+2)%3]);
				pq.push(minx);
			}
		 } 
		 for(int i=1;i<=n;i++)
		{
			dp[i]=dp[i-1]+d[i];
		}
		 ll sum=0;
		 while(cnt[c]>n/2)
		 {
		 	cnt[c]--;
		 	sum+=pq.top();
		 	pq.pop();
		 }
		
		cout<<dp[n]-sum<<"\n";
		
		
	}
	
	return 0;
}
