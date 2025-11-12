#include<bits/stdc++.h>

using namespace std;
int n,a[100010][3];
priority_queue<int> q[3];
int read()
{
	char c=' ';int res=0;
	while(!('0'<=c&&c<='9')) c=getchar();
	while(('0'<=c&&c<='9')) res=res*10+c-'0',c=getchar();
	return res;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=0;i<3;i++) while(q[i].size()) q[i].pop();
		for(int i=1;i<=n;i++)
		  for(int j=0;j<3;j++)
			a[i][j]=read();
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			int maxn=0,maxn_=0,p=0;
			for(int j=0;j<3;j++)
			{
				if(a[i][j]>=maxn)
				  p=j,maxn_=maxn,maxn=a[i][j];
				else if(a[i][j]>=maxn_)
				  maxn_=a[i][j];
			}
			ans+=maxn,q[p].push(maxn_-maxn);
		}
		for(int i=0;i<3;i++)
		{
			while(q[i].size()>n/2)
			{
				ans+=q[i].top();
				q[i].pop();
			}
		}
		printf("%lld\n",ans);
	}
}
