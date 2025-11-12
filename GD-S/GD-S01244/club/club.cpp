#include<bits/stdc++.h>
using namespace std;
int read()
{
	int x=0;bool f=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f=!(ch^45);
	for(;isdigit(ch);ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	return (f?-x:x);
}
priority_queue<int> q[5];
int t,n,sr[5],sl[5],ans;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--)
	{
		n=read();
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++) sr[j]=read();
			for(int j=1;j<=3;j++)
			{
				if(sr[j]>=sr[j%3+1]&&sr[j]>=sr[(j+1)%3+1])
				{
					sl[j]++;
					ans+=sr[j];
					q[j].push(-min(sr[j]-sr[j%3+1],sr[j]-sr[(j+1)%3+1]));
					if(sl[j]>n/2)
					{
						ans-=-q[j].top();
						sl[j]--;
						q[j].pop();
					}
					break;
				}
			}
		}
		printf("%d\n",ans);
		for(int i=1;i<=3;i++)
		{
			while(!q[i].empty()) q[i].pop();
			sl[i]=0;
			ans=0;
		}
	}
}
