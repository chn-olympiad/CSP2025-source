#include<bits/stdc++.h>
using namespace std;

int Q, n, a[100005][3],ans=0;

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> Q;
	while(Q>0)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
			}
		}
		if(n==2)
		{
			int count=0;
			for(int i=1;i<=3;i++)
			{
				for(int j=1;j<=3;j++)
				{
					if(i==j)
					{
						continue;
					}
					else
					{
						count++;
						a[3][count]=a[1][i]+a[2][j];
						ans=max(a[3][count],ans);
					}
				}
			}
			cout<<ans;
		}
		Q--;
	}
	return 0;
}

