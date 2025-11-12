#include<bits/stdc++.h>
using namespace std;
int s[1000005][5],sum[5];
long long ans;
struct stu{
	int mx,mid,chad,mn;
}jiu[10000005];
bool cmp(stu x,stu y)
{
	return x.chad<y.chad;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&s[i][1],&s[i][2],&s[i][3]);
			if(s[i][1]==s[i][2])
			{
				if(s[i][1]>s[i][3])
				{
					jiu[i].mx=1;
					ans+=s[i][1];
					jiu[i].chad=0;
					sum[1]++;
				}
				if(s[i][3]>s[i][1])
				{
					jiu[i].mx=3;
					ans+=s[i][3];
					jiu[i].chad=s[i][3]-s[i][1];
					sum[3]++;
				}
				continue;
			}
			if(s[i][1]==s[i][3])
			{
				if(s[i][1]>s[i][2])
				{
					jiu[i].mx=1;
					ans+=s[i][1];
					jiu[i].chad=0;
					sum[1]++;
				}
				if(s[i][2]>s[i][1])
				{
					jiu[i].mx=2;
					ans+=s[i][2];
					jiu[i].chad=s[i][2]-s[i][1];
					sum[2]++;
				}
				continue;
			}
			if(s[i][3]==s[i][2])
			{
				if(s[i][3]>s[i][1])
				{
					jiu[i].mx=3;
					ans+=s[i][3];
					jiu[i].chad=0;
					sum[3]++;
				}
				if(s[i][1]>s[i][3])
				{
					jiu[i].mx=1;
					ans+=s[i][1];
					jiu[i].chad=s[i][1]-s[i][3];
					sum[1]++;
				}
				continue;
			}
			if(s[i][1]>s[i][2]&&s[i][1]>s[i][3])
			{
				jiu[i].mx=1;
				ans+=s[i][1];
				sum[1]++;
			}
			if(s[i][2]>s[i][1]&&s[i][2]>s[i][3])
			{
				jiu[i].mx=2;
				ans+=s[i][2];
				sum[2]++;
			}
			if(s[i][3]>s[i][2]&&s[i][3]>s[i][1])
			{
				jiu[i].mx=3;
				ans+=s[i][3];
				sum[3]++;
			}
			if(s[i][1]<s[i][2]&&s[i][1]<s[i][3])
			{
				jiu[i].mn=1;
			}
			if(s[i][2]<s[i][1]&&s[i][2]<s[i][3])
			{
				jiu[i].mn=2;
			}
			if(s[i][3]<s[i][2]&&s[i][3]<s[i][1])
			{
				jiu[i].mn=3;
			}
			for(int j=1;j<=3;j++)
			{
				if(jiu[i].mx==j||jiu[i].mn==j) continue;
				jiu[i].mid=j;
				jiu[i].chad=s[i][jiu[i].mx]-s[i][j];
			}
		}
		for(int q=1;q<=3;q++)
		{
			if(sum[q]>n/2)
			{
				sort(jiu+1,jiu+n+1,cmp);
				int num=0;
				for(int i=1;i<=n;i++)
				{
					if(jiu[i].mx==q) ans-=jiu[i].chad,num++;
					if(num==sum[q]-n/2) break;
				}
			}
		}
		printf("%lld\n",ans);
		ans=0;
		for(int i=1;i<=3;i++)
		{
			sum[i]=0;
		}
	}
	return 0;
}