#include<bits/stdc++.h>
using namespace std;
struct sa
{
	int club;
	int h;
	int zh;
}xh[1000005];
bool cmp(sa a,sa b)
{
	return a.zh>b.zh;
}
int zs[1000005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		long long a,b,c;
		long long al=0,bl=0,cl=0;
		long long s=-2;
		long long sum=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a>>b>>c;
			s+=3;
			xh[s].zh=a,xh[s].club=1,xh[s].h=i;
			xh[s+1].zh=b,xh[s+1].club=2,xh[s+1].h=i;
			xh[s+2].zh=c,xh[s+2].club=3,xh[s+2].h=i;
		}
		s=s+2;
		sort(xh+1,xh+1+s,cmp);
		for(int i=1;i<=s;i++)
		{
			if(xh[i].club==1&&al<n/2&&zs[xh[i].h]==0)
			{
				al++;
				sum+=xh[i].zh;
				zs[xh[i].h]=1;
			}
			else if(xh[i].club==2&&bl<n/2&&zs[xh[i].h]==0)
			{
				bl++;
				sum+=xh[i].zh;
				zs[xh[i].h]=1;
			}
			else if(xh[i].club==3&&cl<n/2&&zs[xh[i].h]==0)
			{
				cl++;
				sum+=xh[i].zh;
				zs[xh[i].h]=1;
			}
		}
		cout<<sum<<endl;
		for(int i=1;i<=n;i++)
		{
			zs[i]=0;
		}
	}
	return 0;
}
