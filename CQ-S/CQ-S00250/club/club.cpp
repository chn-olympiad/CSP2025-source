#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
long long T,n,s=0,s2=0,s3=0,ans=0,a[100005][3];
priority_queue<pair<long long,long long> > q;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--)
	{
		s=0,s2=0,s3=0,ans=0;
		cin>>n;
		for(long long i=1;i<=n;i++)
		{
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			long long x=0,v=0,v2=0;
			for(long long j=0;j<=2;j++)
			{
				if(a[i][j]>v)
				{
					v=a[i][j];
					x=j;
				}
			}
			for(long long j=0;j<=2;j++)
			{
				if(a[i][j]>v2&&j!=x)
				{
					v2=a[i][j];
				}
			}
			q.push(make_pair(v2-v,x));
			if(x==0)
			{
				s++;
			}
			else if(x==1)
			{
				s2++;
			}
			else
			{
				s3++;
			}
			ans+=v;
		}
		n/=2;
		while(s>n&&!q.empty())
		{
			long long v=q.top().first,x=q.top().second;	
			if(x==0)
			{
				ans+=v;
				s--;
			}
			q.pop();
		}
		while(s2>n&&!q.empty())
		{
			long long v=q.top().first,x=q.top().second;
			if(x==1)
			{
				ans+=v;
				s2--;
			}
			q.pop();
		}
		while(s3>n&&!q.empty())
		{
			long long v=q.top().first,x=q.top().second;
			if(x==2)
			{
				ans+=v;
				s3--;
			}
			q.pop();
		}
		while(!q.empty())
		{
			q.pop();
		}
		cout<<ans<<endl;
	}
	return 0;
}
