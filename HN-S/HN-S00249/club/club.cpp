//#include<bits/stdc++.h>
//typedef int int32;
//#define int long long
//using namespace std;
///*
//	Author: wbw_121124
//	在洛谷(luogu)上关注我 
//	我要入选HN的集合 
//	炸了
//	人杰地灵
//	club.cpp
//	
//	t1 没必要反悔贪心吧 
//	
//	t1 是反悔贪心！！！ 
//	t1 是反悔贪心！！！ 
//	t1 是反悔贪心！！！ 
//	
//	wwwwwwwwwwwwwwwwwwwww
//*/
//const int N = 1e5 + 5;
//int t,n,a[N][3],ans,vis[N],cnt[3];
////priority_queue<pair<int,int>,vector<pair<int,int>>,
////greater<pair<int,int>>>p,q,r;
//priority_queue<pair<int,int>>q[3];
//signed main()
//{
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0), cout.tie(0);
//	cin>>t;
//	while(t--)
//	{
//		cin>>n;
//		cnt[0]=n;
//		ans=cnt[1]=cnt[2]=0;
//		q[1]=q[2]=priority_queue<pair<int,int>>(); 
//		for(int i=1;i<=n;i++)
//		{
//			vis[i]=0;
//			cin>>a[i][0]>>a[i][1]>>a[i][2];
//			ans+=a[i][0];
//			q[1].push({a[i][1]-a[i][0],i});
//			q[2].push({a[i][2]-a[i][0],i});
//		}
//		for(int i=1;i<=n;i++)
//		{
//			while(!q[1].empty()&&vis[q[1].top().second])
//				q[1].pop();
//			while(!q[2].empty()&&vis[q[2].top().second])
//				q[2].pop();
//			if(cnt[0]<=n/2&&cnt[1]<=n/2&&cnt[2]<=n/2&&
//				max(q[1].top().first,q[2].top().first)<=0)
//				break;
//			if((q[1].top().first>q[2].top().first&&cnt[1]+1<=n/2)||
//				cnt[2]+1>n/2)
//			{
//				vis[q[1].top().second]=1;
//				ans+=q[1].top().first;
//				q[1].pop();
//				cnt[1]++;
//				cnt[0]--;
//			}
//			else
//			{
//				vis[q[2].top().second]=2;
//				ans+=q[2].top().first;
//				q[2].pop();
//				cnt[2]++;
//				cnt[0]--;
//			}
//		}
//		cout<<ans<<'\n';
//	}
//	return 0;
//}
#include<bits/stdc++.h>
typedef int int32;
#define int long long
using namespace std;
/*
	Author: wbw_121124
	人杰地灵 
	club.cpp
*/
const int N = 200 + 5, M = 1e5 + 5;
int t,n,a[M][3],b[M],dp[2][N/2+5][N/2+5][N/2+5],ans;
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>n;
		int cnt=0,tot=0;
		for(int i=1;i<=n;i++)
			cin>>a[i][0]>>a[i][1]>>a[i][2],cnt+=!a[i][1],tot+=!a[i][2];
		if(cnt==n&&tot==n)
		{
			int sum=0;
			for(int i=1;i<=n;i++)
				b[i]=a[i][0];
			sort(b+1,b+1+n,greater<int>());
			for(int i=1;i<=n/2;i++)
				sum+=b[i];
			cout<<sum<<'\n';
			continue;
		}
		if(tot==n)
		{
			int sum=0;
			for(int i=1;i<=n;i++)
				b[i]=a[i][1]-a[i][0],sum+=a[i][0];
			sort(b+1,b+1+n,greater<int>());
			for(int i=1;i<=n/2;i++)
				sum+=b[i];
			cout<<sum<<'\n';
			continue;
		}
		memset(dp[0],0,sizeof dp[0]);
		for(int i=1;i<=n;i++)
		{
			memset(dp[i&1],0,sizeof dp[i&1]);
			for(int j=0;j<=n/2;j++)
				for(int k=0;k<=n/2;k++)
					for(int l=0;l<=n/2;l++)
					{
						if(j)
							dp[i&1][j][k][l]=max(dp[i&1][j][k][l],
								dp[~i&1][j-1][k][l]+a[i][0]);
						if(k)
							dp[i&1][j][k][l]=max(dp[i&1][j][k][l],
								dp[~i&1][j][k-1][l]+a[i][1]);
						if(l)
							dp[i&1][j][k][l]=max(dp[i&1][j][k][l],
								dp[~i&1][j][k][l-1]+a[i][2]);
					}
		}
		for(int i=0;i<=n/2;i++)
			for(int j=0;j<=n/2;j++)
				if(n-i-j<=n/2)
					ans=max(ans,dp[n&1][n-i-j][i][j]);
		cout<<ans<<'\n';
	}
//	cerr<<clock()<<'\n';
	return 0;
}
