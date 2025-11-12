#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
using namespace std;
const int N=1e5+3;
typedef long long ll;
ll t,ans;
ll a[N][4];
priority_queue<int> q;
void dfs(ll k,ll n,ll maxn,int a1,int a2,int a3,ll val)
{
	if(k==n+1)
	{
		ans=max(ans,val);
		return;
	}
	if(a1<maxn&&k<=n)
	{
		int v=val+a[k][1];
		dfs(k+1,n,maxn,a1+1,a2,a3,v);
	}
	if(a2<maxn&&k<=n)
	{
		int v=val+a[k][2];
		dfs(k+1,n,maxn,a1,a2+1,a3,v);
	}
	if(a3<maxn&&k<=n)
	{
		int v=val+a[k][3];
		dfs(k+1,n,maxn,a1,a2,a3+1,v);
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--)
	{
		bool flag=0;
		ll n;
		cin>>n;
		ll maxn=n/2;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
			}
			if(a[i][2]!=0||a[i][3]!=0)
			flag=1;
		}
		if(!flag)
		{
			int x=0;
			for(int i=1;i<=n;i++)
			{
				q.push(a[i][1]);
			}
			while(x<maxn)
			{
				ans+=q.top();
				q.pop();
				x++;
			}
		}
		else
		dfs(1,n,maxn,0,0,0,0);
		cout<<ans<<'\n';
		ans=0;
	}
	return 0;
}
//只会暴力+特判了 
