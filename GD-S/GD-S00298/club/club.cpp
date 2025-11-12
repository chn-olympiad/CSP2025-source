#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,t,sum,c[5],k;
pair<ll,ll>a[5];
priority_queue<ll,vector<ll>,greater<ll> >q[5];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		sum=c[1]=c[2]=c[3]=k=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&a[1].first,&a[2].first,&a[3].first);
			a[1].second=1,a[2].second=2,a[3].second=3;
			sort(a+1,a+4);
			sum+=a[3].first,c[a[3].second]++;
			q[a[3].second].push(a[3].first-a[2].first);
		}
		if(c[1]>n/2)k=1;
		else if(c[2]>n/2)k=2;
		else if(c[3]>n/2)k=3;
		if(k)
		{
			while(c[k]>n/2)
			{
				c[k]--;
				sum-=q[k].top();
				q[k].pop();
			}
			for(int i=1;i<=3;i++)while(!q[i].empty())q[i].pop();
		}
		printf("%lld\n",sum);
	}
	return 0;
}
