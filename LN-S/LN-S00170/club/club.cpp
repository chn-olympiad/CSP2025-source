#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N][4],b[4];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,maxnew,ans=0;
		memset(b,0,sizeof b);
		memset(a,0,sizeof a);
		scanf("%d",&n);
		maxnew=n/2;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				scanf("%d",&a[i][j]);
		for(int i=1;i<=n;i++)
		{
			if(a[i][1]>a[i][2])
				if(a[i][1]>a[i][3])
				{
					b[1]++;
					ans+=a[i][1];
				}
				else
				{
					b[3]++;
					ans+=a[i][3];
				}
			else
			{
				b[2]++;
				ans+=a[i][2];
			}
			if(b[1]>maxnew||b[2]>maxnew||b[3]>maxnew)
				break;
		}
		printf("%d\n",ans);
	}
	return 0;
}
