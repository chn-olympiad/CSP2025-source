#include<bits/stdc++.h>
using namespace std;
struct node
{
	long long num,yh;
}a[500005];
long long n,k,maxn,d[500005],dqn;
void dfs(int t,int step)
{
	for(int i=t;i<=n;i++)
	{
		if((a[t-1].yh^a[i].yh)==k)
		{
			if(d[i]!=0)
			{
				d[i]=dqn-step;
				step=step+d[i];
				if(step>maxn)
				{
					maxn=step;
				}
				return;
			}
			dqn++;
			dfs(i+1,step+1);
			d[i]=dqn-step;
			dqn--;
		}
	}
	if(t+1<=n+1)
	{
		dfs(t+1,step);
	}
	if(step>maxn)
	{
		maxn=step;
	}
	return;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].num;
		a[i].yh=a[i-1].yh^a[i].num;
	}
	dfs(1,0);
	cout<<maxn;
	return 0;
}
