#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define mkp make_pair
#define ft first
#define sc second
using namespace std;
struct node
{
	int a,b,c;
};
node a[100001];
int n,ans=0;
int dp[201][201][201];
vector<int> c1,c2,c3;

priority_queue<pii,vector<pii>,greater<pii> >q1,q2,q3;
bool cmp(node a,node b)
{
	return max(a.a,max(a.b,a.c))>max(b.a,max(b.b,b.c));
}
void dfs(int dep)
{
	if(dep>n)
	{
		int res=0;
		for(int i=0;i<c1.size();i++)res+=a[c1[i]].a;
		for(int i=0;i<c2.size();i++)res+=a[c2[i]].b;
		for(int i=0;i<c3.size();i++)res+=a[c3[i]].c;
		//cerr<<res<<"\n";
		ans=max(ans,res);
		return ;
	}
	if(c1.size()<(n>>1))
	{
		c1.pb(dep);
		dfs(dep+1);
		c1.pop_back();
	}
	if(c2.size()<(n>>1))
	{
		c2.pb(dep);
		dfs(dep+1);
		c2.pop_back();
	}
	if(c3.size()<(n>>1))
	{
		c3.pb(dep);
		dfs(dep+1);
		c3.pop_back();
	}
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		
		//c1.clear(),c2.clear(),c3.clear();
		//q1.clear(),q2.clear(),q3.clear();
		/*
		while(!q1.empty())q1.pop();
		while(!q2.empty())q2.pop();
		while(!q3.empty())q3.pop();*/
		ans=0;
		cin>>n;
		bool flga=1,flgb=1;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].a>>a[i].b>>a[i].c;
			flga=flga&&(a[i].b==0&&a[i].c==0);
			flgb=flgb&&(a[i].c==0);
		}
		if(flga)
		{
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=(n>>1);i++)
				ans+=a[i].a;
			cout<<ans<<'\n';
			continue;
		}
		if(n<=16)
		{
			dfs(1);
			cout<<ans<<'\n';
			continue;
		}
		if(n<=200)
		{
			//for(int l=1;l<=n;l++)
				//memset(dp,0,sizeof(dp));
			for(int i=0;i<=(n>>1);i++)
				for(int j=0;j<=(n>>1);j++)
					for(int k=0;k<=(n>>1);k++)
					{
						if(i+j+k>n)break;
						if(i!=0)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i+k+j].a);
						if(j!=0)dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k]+a[i+k+j].b);
						if(k!=0)dp[i][j][k]=max(dp[i][j][k],dp[i][j][k-1]+a[i+k+j].c);
					}	
			if(flgb)
			{
				cout<<dp[n>>1][n>>1]<<"\n";
				continue;
			}
			cout<<ans<<"\n";
			continue;	
		}
		for(int i=1;i<=n;i++)
		{
			int t=max(a[i].a,max(a[i].b,a[i].c));
			if(t==a[i].a)
			{
				if(q1.size()<(n>>1))q1.push(mkp(a[i].a,i));
				else
				{
					auto u=q1.top();
					if(u.ft<a[i].a)
					{
						q1.pop(),q1.push(mkp(a[i].a,i));
						int ut=max(a[u.sc].b,a[u.sc].c);
						if(ut==a[u.sc].b&&q2.size()<(n>>1))
							q2.push(mkp(ut,u.sc));
						else if(ut==a[u.sc].c&&q3.size()<(n>>1))
							q3.push(mkp(ut,u.sc));
						else if(q2.size()<(n>>1))
							q2.push(mkp(a[u.sc].c,u.sc));
						else
							q3.push(mkp(a[u.sc].c,u.sc));
						continue;
					}
					int ut=max(a[i].b,a[i].c);
					if(ut==a[i].b&&q2.size()<(n>>1))
						q2.push(mkp(ut,i));
					else if(ut==a[i].c&&q3.size()<(n>>1))
						q3.push(mkp(ut,i));
					else if(q2.size()<(n>>1))
						q2.push(mkp(a[i].b,i));
					else
						q3.push(mkp(a[i].c,i));
				}
			}
			else if(t==a[i].b)
			{
				if(q2.size()<(n>>1))q2.push(mkp(a[i].b,i));
				else
				{
					auto u=q2.top();
					if(u.ft<a[i].b)
					{
						q2.pop(),q2.push(mkp(a[i].b,i));
						int ut=max(a[u.sc].a,a[u.sc].c);
						if(ut==a[u.sc].a&&q1.size()<(n>>1))
							q1.push(mkp(ut,u.sc));
						else if(ut==a[u.sc].c&&q3.size()<(n>>1))
							q3.push(mkp(ut,u.sc));
						else if(q1.size()<(n>>1))
							q1.push(mkp(a[u.sc].a,u.sc));
						else
							q3.push(mkp(a[u.sc].c,u.sc));
						continue;
					}
					int ut=max(a[i].a,a[i].c);
					if(ut==a[i].a&&q1.size()<(n>>1))
						q1.push(mkp(ut,i));
					else if(ut==a[i].c&&q3.size()<(n>>1))
						q3.push(mkp(ut,i));
					else if(q1.size()<(n>>1))
						q1.push(mkp(a[i].a,i));
					else
						q3.push(mkp(a[i].c,i));
				}
			}
			else if(t==a[i].c)
			{
				if(q3.size()<(n>>1))q3.push(mkp(a[i].c,i));
				else
				{
					auto u=q3.top();
					if(u.ft<a[i].c)
					{
						q3.pop(),q3.push(mkp(a[i].c,i));
						int ut=max(a[u.sc].b,a[u.sc].a);
						if(ut==a[u.sc].b&&q2.size()<(n>>1))
							q2.push(mkp(ut,u.sc));
						else if(ut==a[u.sc].a&&q1.size()<(n>>1))
							q1.push(mkp(ut,u.sc));
						else if(q2.size()<(n>>1))
							q2.push(mkp(a[u.sc].b,u.sc));
						else
							q1.push(mkp(a[u.sc].a,u.sc));
						continue;
					}
					int ut=max(a[i].b,a[i].a);
					if(ut==a[i].b&&q2.size()<(n>>1))
						q2.push(mkp(ut,i));
					else if(ut==a[i].a&&q1.size()<(n>>1))
						q1.push(mkp(ut,i));
					else if(q2.size()<(n>>1))
						q2.push(mkp(a[i].b,i));
					else
						q1.push(mkp(a[i].a,i));
				}
			}
		}
		while(!q1.empty())ans=q1.top().ft,q1.pop();
		while(!q2.empty())ans+=q2.top().ft,q2.pop();
		while(!q3.empty())ans+=q3.top().ft,q3.pop();
		cout<<ans<<"\n";
	}
	fclose(stdout);
	fclose(stdin);
	return 0;
}
