#include <bits/stdc++.h>
using namespace std;

int n;

const int M=1e5+5;
int a[M][5];
int b1[M],b2[M],b3[M];

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while (T--)
	{
		cin>>n;
		int cnt1=0,cnt2=0,cnt3=0;
		int ans=0;
		for (int i=1; i<=n; i++)
		{
			scanf("%d %d %d",&a[i][1],&a[i][2],&a[i][3]);
			if (a[i][1]>=a[i][2] and a[i][1]>=a[i][3])
			{
				ans+=a[i][1];
				b1[++cnt1]=min(a[i][1]-a[i][2],a[i][1]-a[i][3]);
			}
			else if (a[i][2]>=a[i][1] and a[i][2]>=a[i][3])
			{
				ans+=a[i][2];
				b2[++cnt2]=min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
			}
			else
			{
				ans+=a[i][3];
				b3[++cnt3]=min(a[i][3]-a[i][1],a[i][3]-a[i][2]);
			}
		}
		if (max(max(cnt1,cnt2),cnt3)<=n/2)
		{
			cout<<ans<<"\n";
			continue;
		}
		if (cnt1>n/2)
		{
			sort(b1+1,b1+cnt1+1);
			for (int i=1; i<=cnt1-n/2; i++) ans-=b1[i];
			cout<<ans<<"\n";
		}
		else if (cnt2>n/2)
		{
			sort(b2+1,b2+cnt2+1);
			for (int i=1; i<=cnt2-n/2; i++) ans-=b2[i];
			cout<<ans<<"\n";
		}
		else
		{
			sort(b3+1,b3+cnt3+1);
			for (int i=1; i<=cnt3-n/2; i++) ans-=b3[i];
			cout<<ans<<"\n";
		}
	}
	return 0;
}
