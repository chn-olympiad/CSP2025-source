#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fir first
#define sec second
using namespace std;

int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
const int maxn=1e5+9;
int a[maxn][5];
void solve()
{
	priority_queue<int,vector<int>,greater<int>>q1,q2,q3;
	int n;
	n=read();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
		{
			a[i][j]=read();
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i][1]>=max(a[i][2],a[i][3]))
		{
			q1.push(a[i][1]-max(a[i][2],a[i][3]));
			ans+=a[i][1];
			if(q1.size()>n/2)
			{
				ans-=q1.top();
				q1.pop();
			}
		}	
		else if(a[i][2]>=max(a[i][1],a[i][3]))
		{
			q2.push(a[i][2]-max(a[i][1],a[i][3]));
			ans+=a[i][2];
			if(q2.size()>n/2)
			{
				ans-=q2.top();
				q2.pop();
			}
		}
		else
		{
			q3.push(a[i][3]-max(a[i][1],a[i][2]));
			ans+=a[i][3];
			if(q3.size()>n/2)
			{
				ans-=q3.top();
				q3.pop();
			}
		}
	}	
	printf("%d\n",ans);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	T=read();
	while(T--)solve();
	return 0;
}

