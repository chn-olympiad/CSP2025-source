#include <bits/stdc++.h>
using namespace std;
int a[1145141],b[1145141],c[1145141];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		int ans=0;
		for(int i=1;i<=n;i++)scanf("%d %d %d",&a[i],&b[i],&c[i]);
		int sum=0;
		priority_queue<int,vector<int>,greater<int> >q;
		for(int i=1;i<=n;i++)
		{
			sum+=a[i];
			q.push(min(a[i]-b[i],a[i]-c[i]));
		}
		while(q.size()>n/2)sum-=q.top(),q.pop();
		ans=max(ans,sum);
		sum=0;
		while(!q.empty())q.pop();
		for(int i=1;i<=n;i++)
		{
			sum+=b[i];
			q.push(min(b[i]-a[i],b[i]-c[i]));
		}
		while(q.size()>n/2)sum-=q.top(),q.pop();
		ans=max(ans,sum);
		sum=0;
		while(!q.empty())q.pop();
		for(int i=1;i<=n;i++)
		{
			sum+=c[i];
			q.push(min(c[i]-b[i],c[i]-a[i]));
		}
		while(q.size()>n/2)sum-=q.top(),q.pop();
		ans=max(ans,sum);
		int sz1=0,sz2=0,sz3=0;
		sum=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>b[i]&&a[i]>c[i])sz1++;
			else if(b[i]>a[i]&&b[i]>c[i])sz2++;
			else if(c[i]>a[i]&&c[i]>b[i])sz3++;
		}
		if(sz1>n/2||sz2>n/2||sz3>n/2)cout<<ans<<'\n';
		else
		{
			bool flag=0;
			int sum=0;
			for(int i=1;i<=n;i++)
			{
				int maxx=max({a[i],b[i],c[i]});
				sum+=maxx;
				int s=0;
				if(a[i]==maxx)s++;
				if(b[i]==maxx)s++;
				if(c[i]==maxx)s++;
				if(s>=2)
				{
					if(a[i]==maxx&&b[i]==maxx)
					{
						sz1++;
						if(sz1>n/2)sz2++;
						if(sz2>n/2)
						{
							flag=1;
							break;
						}
					}
					if(b[i]==maxx&&c[i]==maxx)
					{
						sz2++;
						if(sz2>n/2)sz3++;
						if(sz3>n/2)
						{
							flag=1;
							break;
						}
					}
					if(a[i]==maxx&&c[i]==maxx)
					{
						sz1++;
						if(sz1>n/2)sz3++;
						if(sz3>n/2)
						{
							flag=1;
							break;
						}
					}
					if(a[i]==maxx&&b[i]==maxx&&c[i]==maxx)
					{
						sz1++;
						if(sz1>n/2)sz2++;
						if(sz2>n/2)sz3++;
						if(sz3>n/2)
						{
							flag=1;
							break;
						}
					}
				}
			}
			if(flag)cout<<ans<<'\n';
			else cout<<max(ans,sum)<<'\n';
		}
	}
	return 0;
}
