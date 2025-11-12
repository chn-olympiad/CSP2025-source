#include <bits/stdc++.h>
using namespace std;
int t,n,a[100005][4];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for (int o = 1;o <= t;o++)
	{
		cin >> n;
		int k = n/2;
		for (int i = 1;i <= n;i++)
		{
			cin >> a[i][1]>>a[i][2]>>a[i][3];
		}
		int f[10005],g[10005],h[10005];
		for (int i = 1;i <= n;i++)
		{
			f[i]=a[i][1];
			g[i]=a[i][2];
			h[i]=a[i][3];
		}
		sort(f+1,f+n+1);
		sort(g+1,g+n+1);
		sort(h+1,h+n+1);
		if (n==2)
		{
			int ans=-9;
			ans=max(ans,a[1][1]+a[2][2]);
			ans=max(ans,a[1][1]+a[2][3]);
			ans=max(ans,a[1][2]+a[2][1]);
			ans=max(ans,a[1][2]+a[2][3]);
			ans=max(ans,a[1][3]+a[2][1]);
			ans=max(ans,a[1][3]+a[2][2]);
			cout << ans << endl;
		}
		else if (n==4)
		{
			int as=0,df=0,gh=0;
			for (int i = 1;i <= n;i++)
			{
				as+=a[i][1];
				df+=a[i][2];
				gh+=a[i][3];
			}
			int qw=0,er=0,ty=0;
			for (int i = k+1;i<=n;i++)
			{
				qw+=a[i][1];
				er+=a[i][2];
				ty+=a[i][3];
			}
			int ans=0;
			if(qw>er&&qw>ty)
			{
				ans+=qw;
				
			}
			cout << ans+2;
		}
		else
		{
			int k = n/2;
			for (int i = 1;i <= n;i++)
			{
				cin >> a[i].a>>a[i].b>>a[i].c;
				as[i]=a[i][1];
				df[i]=a[i][2];
				gh[i]=a[i][3];
			}
			int ans=0;
			for (int i = 1;i <= n;i++)
			{
				ans+=max(max(as[i],df[i]),gh[i]);
			}
			cout << ans<<endl;
			}
		}
	}
	return 0;
}
