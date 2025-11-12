#include <bits/stdc++.h>
using namespace std;
int t,n,a[100005][5],f[100005][5];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int x=1;x<=t;x++)
	{
	    cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
			}
		}
		int ans=max(max(a[1][1],a[1][2]),a[1][3]);
		for(int i=2;i<=n;i++)
		{
		    for(int j=1;j<=3;j++)
			{
			    f[i][j]=f[i-1][j];
				f[i][j]=max(f[i][j],f[i-1][j]+a[i][j]);
				ans=max(f[i][j],ans);	
			}
		}
		cout<<ans<<endl;	
	}
	return 0;
}
