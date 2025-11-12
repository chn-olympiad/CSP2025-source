#include<bits/stdc++.h>
#define ll long long
using namespace std;
int t;
int n;
ll a[100010][4];
int ss[100010];
vector<ll> v;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		ll ans=0;
		scanf("%d",&n);
		for(register int i=1;i<=n;i++)
			for(register int j=1;j<=3;j++)
				scanf("%lld",&a[i][j]);
		int s1=0,s2=0,s3=0;
		for(register int i=1;i<=n;i++)
		{
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]) ans+=a[i][1],s1++,ss[i]=1;
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]) ans+=a[i][2],s2++,ss[i]=2;
			else ans+=a[i][3],s3++,ss[i]=3;
		}
		if(s1<=n/2&&s2<=n/2&&s3<=n/2)
		{
			printf("%lld\n",ans);
			continue;
		}
		for(register int i=1;i<=n;i++)
		{
			if(s1>n/2&&ss[i]==1)
			{
				if(a[i][2]>=a[i][3]) v.push_back(a[i][1]-a[i][2]);
				else v.push_back(a[i][1]-a[i][3]);
			}
			if(s2>n/2&&ss[i]==2)
			{
				if(a[i][1]>=a[i][3]) v.push_back(a[i][2]-a[i][1]);
				else v.push_back(a[i][2]-a[i][3]);
			}
			if(s3>n/2&&ss[i]==3)
			{
				if(a[i][1]>=a[i][2]) v.push_back(a[i][3]-a[i][1]);
				else v.push_back(a[i][3]-a[i][2]);
			}
		}
		sort(v.begin(),v.end());
		int sss=max(max(s1,s2),s3)-n/2;
		for(register int i=0;i<sss;i++) ans-=v[i];
		printf("%lld\n",ans);
		v.clear();
	}
	return 0;
}
