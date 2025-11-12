#include<bits/stdc++.h>
using namespace std;
int t,n,a[100100][5],dp[100100][5],ans=0;

bool pd(){
	for (int i=1;i<=n;i++)
			if (a[i][1]==a[i][2]||a[i][1]==a[i][3]||a[i][2]==a[i][3])
				continue;
			else return false;
	return true;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while (t--)
	{
		ans=0;
		cin>>n;
		for (int i=1;i<=n;i++)
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		if (n==2)
		{
				for (int j=1;j<=3;j++)
					for (int k=1;k<=3;k++)
						if (j!=k)
							ans=max(ans,a[1][j]+a[2][k]);
				cout<<ans<<endl;
		}
		else if (pd()&&n==4)
		{
			int nol=0;
			for (int i=1;i<=3;i++)
				if (a[1][i]!=0)nol=i;
			for (int i=1;i<=n;i++)
				for (int j=i+1;j<=n;j++)
					ans=max(a[i][nol]+a[j][nol],ans);
			cout<<ans<<endl;
			
		}
		else
		{
			int lastj=0;
			for (int i=1;i<=n;i++)
			{
				int maxx=0;
				for (int j=1;j<=3;j++)
					if (lastj!=j)
					{
						if (maxx<a[i][j])
							maxx=a[i][j],lastj=j;
					}
				ans+=maxx;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}

