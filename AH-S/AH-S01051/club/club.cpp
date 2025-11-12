#include<bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,greater<int>> q1,q2,q3;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		while(!q1.empty())q1.pop();
		while(!q2.empty())q2.pop();
		while(!q3.empty())q3.pop();
		int n,x,y,z,s1=0,s2=0,s3=0,ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&x,&y,&z);
			if(x>=y&&x>=z)
			{
				ans+=x,s1++;
				q1.push(min(x-y,x-z));
			}
			else if(y>x&&y>=z)
			{
				ans+=y,s2++;
				q2.push(min(y-x,y-z));
			}
			else
			{
				ans+=z,s3++;
				q3.push(min(z-x,z-y));
			}
		}
		while(s1>n/2)
		{
			ans-=q1.top(),s1--;
			q1.pop();
		}
		while(s2>n/2)
		{
			ans-=q2.top(),s2--;
			q2.pop();
		}
		while(s3>n/2)
		{
			ans-=q3.top(),s3--;
			q3.pop();
		}
		printf("%d\n",ans);
	}
	return 0;
}
