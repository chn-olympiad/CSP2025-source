#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
int t,n;
long long ans;
int sum[4];
int a[MAXN][6];
priority_queue<int> q1,q2,q3;
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
void solve(int a[])
{
	int id1=0,id2=0,mx=-1,cmx=-1;
	for(int i=1;i<=3;i++)
	{
		if(a[i]>mx)
		{
			cmx=mx,id2=id1;
			mx=a[i],id1=i;
		}
		else if(a[i]>cmx)
		{
			cmx=a[i],id2=i;
		}
	}
	a[4]=id1,a[5]=id2;
	return ;
}
void work()
{
	while(q1.size())
	{
		q1.pop();
	}
	while(q2.size())
	{
		q2.pop();
	}
	while(q3.size())
	{
		q3.pop();
	}
	ans=0;
	sum[1]=sum[2]=sum[3]=0;
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i][1]=read();
		a[i][2]=read();
		a[i][3]=read();
		solve(a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		int x=a[i][4],y=a[i][5],s=0;
		if(sum[x]<n/2)
		{
			ans+=a[i][x];
			if(x==1) q1.push(a[i][y]-a[i][x]);
			else if(x==2) q2.push(a[i][y]-a[i][x]);
			else q3.push(a[i][y]-a[i][x]);
			sum[x]++;
		}
		else
		{
			if(x==1)
			{
				q1.push(a[i][y]-a[i][x]);
				ans+=q1.top();
				q1.pop();
			}
			else if(x==2)
			{
				q2.push(a[i][y]-a[i][x]);
				ans+=q2.top();
				q2.pop();
			}
			else
			{
				q3.push(a[i][y]-a[i][x]);
				ans+=q3.top();
				q3.pop();
			}
			ans+=a[i][x];
		}
	}
	printf("%lld\n",ans);
	return ;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--) work();
	return 0;
}
