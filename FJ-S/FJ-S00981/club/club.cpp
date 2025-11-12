#include<bits/stdc++.h>
using namespace std;
struct node{
	int c1,c2,c3; 
};
node a[100005];
bool cmp(node x,node y)
{
	return x.c1+x.c2+x.c3>y.c1+y.c2+y.c3;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		int n,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].c1>>a[i].c2>>a[i].c3;
		}
		sort(a+1,a+1+n,cmp);
		int cnt1=0,cnt2=0,cnt3=0;
		for(int i=1;i<=n;i++)
		{
			if(max(a[i].c1,max(a[i].c2,a[i].c3))==a[i].c1)
			{
				if(cnt1<n/2)
				{
					cnt1++;
					ans+=a[i].c1;
				}
				else if(max(a[i].c2,a[i].c3)==a[i].c2)
				{
					if(cnt2<n/2)
					{
						cnt2++;
						ans+=a[i].c2;
					}
					else
					{
						ans+=a[i].c3;
						cnt3++;
					}
				}
				else
				{
					ans+=a[i].c3;
					cnt3++;
				}
			}
			else
			{
				if(max(a[i].c2,a[i].c3)==a[i].c2)
				{
					if(cnt2<n/2)
					{
						cnt2++;
						ans+=a[i].c2;
					}
					else
					{
						ans+=a[i].c3;
						cnt3++;
					}
				}
				else
				{
					ans+=a[i].c3;
					cnt3++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
