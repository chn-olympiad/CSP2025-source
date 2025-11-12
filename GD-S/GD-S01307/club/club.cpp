#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int t,n,ans,a[100005], b[100005], c[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	for (int i=1;i<=t;i++)
	{
		ans=0;
		cin >> n;
		for (int j=1;j<=n;j++)
		{
			cin >> a[j] >> b[j] >> c[j];
		}
		sort(a+1,a+n+1,cmp);
		for (int i=1;i<=n;i++)
		{
		    if (a[i]>=b[i])
		    {
		    	if (a[i]>=c[i])
		    	{
		    		ans+=a[i];
				}
			}
	    } 
	    sort(b+1,b+n+1,cmp);
		for (int i=1;i<=n;i++)
		{
			if (b[i]>=a[i])
			{
				if (b[i]>=c[i])
				{
					ans+=b[i];
				}
			}
		}
		sort(c+1,c+n+1,cmp);
		for (int i=1;i<=n;i++)
		{
			if (c[i]>=a[i])
			{
				if (c[i]>=b[i])
				{
					ans+=c[i]; 
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
