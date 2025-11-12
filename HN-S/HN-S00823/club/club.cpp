//rp++;
#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=1e5+5;
struct node
{
	int x,idx;
}a[N][5];
struct bcmf
{
	int y,id1,id2,id3;
}dp[N][5];
priority_queue<int> q1,q2,q3;
//vector<node> v[N];
int vis[N];
bool cmp(node s,node l)
{
	return s.x>l.x;
}

signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int cntx=0,cnty=0,cntz=0,cnti=0,cntj=0,cntk=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1].x>>a[i][2].x>>a[i][3].x;
			q1.push(a[i][1].x);
			q2.push(a[i][2].x);
			q3.push(a[i][3].x);
			if(a[i][2].x==0&&a[i][3].x==0)
			{
				cntx++;
			}
			if(a[i][1].x==0&&a[i][3].x==0)
			{
				cnty++;
			}
			if(a[i][1].x==0&&a[i][2].x==0)
			{
				cntz++;
			}
			if(a[i][1].x==0)
			{
				cnti++;
			}
			if(a[i][2].x==0)
			{
				cntj++;
			}
			if(a[i][3].x==0)
			{
				cntk++;
			}
			a[i][1].idx=1;
			a[i][2].idx=2;
			a[i][3].idx=3;
//			v[i].push_back(a[i][j]);
	 	}
	 	int z=n/2;
	 	if(cntx==n)
	 	{
	 		int s=0;
	 		while(z--)
	 		{
	 			s+=q1.top();
	 			q1.pop();
			}
			cout<<s<<endl;
			continue;
		}
		if(cnty==n)
	 	{
	 		int s=0;
	 		while(z--)
	 		{
	 			s+=q2.top();
	 			q2.pop();
			}
			cout<<s<<endl;
			continue;
		}
		if(cntz==n)
	 	{
	 		int s=0;
	 		while(z--)
	 		{
	 			s+=q3.top();
	 			q3.pop();
			}
			cout<<s<<endl;
			continue;
		}
		if(cnti==n)
		{
			int s=0;
			while(z--)
			{
				s=s+q2.top()+q3.top();
				q2.pop();
				q3.pop(); 
			}
			cout<<s<<endl;
			continue;
		}
		if(cntj==n)
		{
			int s=0;
			while(z--)
			{
				s=s+q1.top()+q3.top();
				q1.pop();
				q3.pop(); 
			}
			cout<<s<<endl;
			continue;
		}
		if(cntk==n)
		{
			int s=0;
			while(z--)
			{
				s=s+q2.top()+q1.top();
				q2.pop();
				q1.pop(); 
			}
			cout<<s<<endl;
			continue;
		}
//	 	for(int i=1;i<=n;i++)
//	 	{
//	 		sort(v[i].begin(),v[i].end(),cmp);
//		}
		memset(dp,0,sizeof(dp));
		int cnt1=0,cnt2=0,cnt3=0;
		int limit=n/2;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				dp[i][j].y=max(dp[i][j].y,
				max(max(a[i][j].x+dp[i-1][j].y,
				a[i][j].x+dp[i-1][j-1].y),
				a[i][j].x+dp[i-1][j+1].y));
				if(a[i][j].idx==1)
				{
					if(dp[i-1][j].y>dp[i-1][j-1].y
					&&dp[i-1][j].y>dp[i-1][j+1].y)
					{
						dp[i][j].id1=dp[i-1][j].id1+1;
					}
					else if(dp[i-1][j-1].y>dp[i-1][j].y
					&&dp[i-1][j-1].y>dp[i-1][j+1].y)
					{
						dp[i][j].id1=dp[i-1][j-1].id1+1;
					}
					else if(dp[i-1][j+1].y>dp[i-1][j].y
					&&dp[i-1][j+1].y>dp[i-1][j-1].y)
					{
						dp[i][j].id1=dp[i-1][j+1].id1+1;
					}
				}
				else if(a[i][j].idx==2)
				{
					if(dp[i-1][j].y>dp[i-1][j-1].y
					&&dp[i-1][j].y>dp[i-1][j+1].y)
					{
						dp[i][j].id2=dp[i-1][j].id2+1;
					}
					else if(dp[i-1][j-1].y>dp[i-1][j].y
					&&dp[i-1][j-1].y>dp[i-1][j+1].y)
					{
						dp[i][j].id2=dp[i-1][j-1].id2+1;
					}
					else if(dp[i-1][j+1].y>dp[i-1][j].y
					&&dp[i-1][j+1].y>dp[i-1][j-1].y)
					{
						dp[i][j].id2=dp[i-1][j+1].id2+1;
					}
				}
				else
				{
					if(dp[i-1][j-1].y>dp[i-1][j].y
					&&dp[i-1][j-1].y>dp[i-1][j+1].y)
					{
						dp[i][j].id3=dp[i-1][j].id3+1;
					}
					else if(dp[i-1][j].y>dp[i-1][j-1].y
					&&dp[i-1][j].y>dp[i-1][j+1].y)
					{
						dp[i][j].id3=dp[i-1][j-1].id3+1;
					}
					else if(dp[i-1][j+1].y>dp[i-1][j].y
					&&dp[i-1][j+1].y>dp[i-1][j-1].y)
					{
						dp[i][j].id3=dp[i-1][j+1].id3+1;
					}
				}
				if(dp[i][j].id1>limit||dp[i][j].id2>limit
				||dp[i][j].id3>limit)
				{
					dp[i][j].y=INT_MIN;
					dp[i][j].id1=INT_MAX;
					dp[i][j].id2=INT_MAX;
					dp[i][j].id3=INT_MAX;
				}
			}
		}
		int res=INT_MIN;
		for(int i=1;i<=3;i++)
		{
			res=max(res,dp[n][i].y);
		}
		cout<<res<<endl;
	}
	return 0;
}
//Ren5Jie4Di4Ling5%  password
//this oier is dead!
