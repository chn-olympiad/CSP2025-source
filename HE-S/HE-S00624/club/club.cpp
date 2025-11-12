#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
const int M=2e5+10;
int t,a[M][5],n,max1,pos1,max2,pos2,max3,pos3,b[M][5],ans;
priority_queue<int> q;
void dfs(int x,int cnt,int q1,int q2,int q3)
{
	if(x==n+1)
	{
		ans=max(ans,cnt);
		return;
	}
	if(q1<n/2)
	{
		dfs(x+1,cnt+a[x][1],q1+1,q2,q3);
	}
	if(q2<n/2)
	{
		dfs(x+1,cnt+a[x][2],q1,q2+1,q3);
	}
	if(q3<n/2)
	{
		dfs(x+1,cnt+a[x][3],q1,q2,q3+1);
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>n;
		for (int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			q.push(a[i][2]);
		}
		if(n<=30)
		{
			dfs(1,0,0,0,0);
			cout<<ans<<"\n";
		}
		else
		{
			int anss=0;
			for(int i=1;i<=n;i++)
			{
				if(i<=n/2)anss+=q.top();
				q.pop();
			}
			cout<<anss<<"\n";
		}
	}
	return 0;
}

