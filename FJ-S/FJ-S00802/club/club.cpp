#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,n;
struct node
{
	int c[4];
	int max1,max2;
	bool g;
}a[100005];
int cnt[5];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		int ans=0;
		for(int i=1;i<=3;i++) cnt[i]=0;
		for(int i=1;i<=n;i++) 
		{
			a[i].g=false;
			cin>>a[i].c[1]>>a[i].c[2]>>a[i].c[3];
			int maxn=max(a[i].c[1],max(a[i].c[2],a[i].c[3]));
			if(a[i].c[1]==maxn)
			{
				cnt[1]++,a[i].max1=a[i].c[1];
				a[i].max2=max(a[i].c[2],a[i].c[3]);
			}
			else if(a[i].c[2]==maxn)
			{
				cnt[2]++,a[i].max1=a[i].c[2];
				a[i].max2=max(a[i].c[1],a[i].c[3]);
			}
			else if(a[i].c[3]==maxn)
			{
				cnt[3]++,a[i].max1=a[i].c[3];
				a[i].max2=max(a[i].c[1],a[i].c[2]);
			}
			ans+=maxn;
		}
		for(int i=1;i<=3;i++)
		{
			if(cnt[i]>n/2)
			{
				while(cnt[i]>n/2)
				{
					int id=0,minx=1e9;
					for(int j=1;j<=n;j++)
					{
						if(a[j].max1==a[j].c[i]&&a[j].g==false)
						{
							if((a[j].max1-a[j].max2)<minx)
							{
								id=j,minx=a[j].max1-a[j].max2;
							}
						}
					}
					cnt[i]--,ans-=(a[id].max1-a[id].max2),a[id].g=true;
				}
				break;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
