#include<bits/stdc++.h>
using namespace std;
int t,n,ans=0;
struct myd
{
	int one,two,three;
	int m=max(one,max(two,three));
	int s=min(one,min(two,three));
}a[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		scanf("%d",&n);
		int f1=0,s2=0,t3=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d%d%d",&a[i].one,&a[i].two,&a[i].three);
		}
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(a[i].m>a[j].m)
				{
					swap(a[i],a[j]);
				}
			}
		}
		for(int i=0;i<n;i++)
		{
			if(a[i].one==a[i].m&&f1<n/2)
			{
				ans+=a[i].one;
				f1++;
			}
			else if(a[i].two==a[i].m&&s2<n/2)
			{
				ans+=a[i].two;
				s2++;
			}
			else if(a[i].three==a[i].m&&t3<n/2)
			{
				ans+=a[i].three;
				t3++;
			}
			else
			{
				if(a[i].one!=a[i].s&&f1<n/2)
				{
					ans+=a[i].one;
					f1++;
				}
				else if(a[i].two!=a[i].s&&s2<n/2)
				{
					ans+=a[i].two;
					s2++;
				}
				else if(a[i].three!=a[i].s&&t3<n/2)
				{
					ans+=a[i].three;
					t3++;
				}
				else
				{
					if(f1<n/2)
					{
						ans+=a[i].one;
						f1++;
					}
					else if(s2<n/2)
					{
						ans+=a[i].two;
						s2++;
					}
					else if(t3<n/2)
					{
						ans+=a[i].three;
						t3++;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
