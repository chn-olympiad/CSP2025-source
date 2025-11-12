#include<bits/stdc++.h>
using namespace std;
int n;
priority_queue<int>q0,q1,q2;
void solve()
{
	while(!q0.empty()) q0.pop();
	while(!q1.empty()) q1.pop();
	while(!q2.empty()) q2.pop();
	scanf("%d",&n);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if(x>=y&&x>=z)
		{
			ans+=x;
			if(y>z) q0.push(y-x);
			else q0.push(z-x);
		}
		else if(y>=x&&y>=z)
		{
			ans+=y;
			if(x>z) q1.push(x-y);
			else q1.push(z-y);
		}
		else
		{
			ans+=z;
			if(x>y) q2.push(x-z);
			else q2.push(y-z);
		}
	}
	while(int(q0.size())*2>n)
	{
		ans+=q0.top();
		q0.pop();
	}
	while(int(q1.size())*2>n)
	{
		ans+=q1.top();
		q1.pop();
	}
	while(int(q2.size())*2>n)
	{
		ans+=q2.top();
		q2.pop();
	}
	printf("%d\n",ans);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--) solve(); 
	return 0;
}
