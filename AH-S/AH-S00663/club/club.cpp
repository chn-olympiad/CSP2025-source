#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[100005][5],b[100005],c[100005];
int n;
bool cmp(int x,int y)
{
	return x>y;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		int cnt1,cnt2,cnt3,sum,cnt;
		cnt1=cnt2=cnt3=cnt=sum=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for(int i=1;i<=n;i++)
		{
			sum+=max({a[i][1],a[i][2],a[i][3]});
			if(max({a[i][1],a[i][2],a[i][3]})==a[i][1])
			{
				b[i]=1;
				cnt1++;
			}
			else if(max({a[i][1],a[i][2],a[i][3]})==a[i][2])
			{
				b[i]=2;
				cnt2++;
			}
			else if(max({a[i][1],a[i][2],a[i][3]})==a[i][3])
			{
				b[i]=3;
				cnt3++;
			}
		}
		if(cnt1*2>n)
		{
			for(int i=1;i<=n;i++)
			{
				if(b[i]==1)
				{
					if(a[i][3]-a[i][1]>a[i][2]-a[i][1])
					{
						c[++cnt]=a[i][3]-a[i][1];
					}
					else
					{
						c[++cnt]=a[i][2]-a[i][1];
					}
				}
			}
		}
		else if(cnt2*2>n)
		{
			for(int i=1;i<=n;i++)
			{
				if(b[i]==2)
				{
					if(a[i][3]-a[i][2]>a[i][1]-a[i][2])
					{
						c[++cnt]=a[i][3]-a[i][2];
					}
					else
					{
						c[++cnt]=a[i][1]-a[i][2];
					}
				}
			}
		}
		else if(cnt3*2>n)
		{
			for(int i=1;i<=n;i++)
			{
				if(b[i]==3)
				{
					if(a[i][1]-a[i][3]>a[i][2]-a[i][3])
					{
						c[++cnt]=a[i][1]-a[i][3];
					}
					else
					{
						c[++cnt]=a[i][2]-a[i][3];
					}
				}
			}
		}
		if(cnt)
		{
			sort(c+1,c+cnt+1,cmp);
			for(int i=1;i<=cnt-n/2;i++)
			{
				sum+=c[i];
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}
/*
*/
