#include<bits/stdc++.h>
using namespace std;
//Start to do This Problem at 14:31 P.M.
//Complet This Problem at 15:25 P.M.
//Just can take a section of score,about 20~50 points.
//Oh noooooooooo!
struct node
{
	int c1,c2,c3;
}a[1000010];
int ans=0;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		int d1,d2,d3;
		d1=d2=d3=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i].c1,&a[i].c2,&a[i].c3);
			if(a[i].c1>a[i].c2&&a[i].c1>a[i].c3&&d1<=n>>1)
			{
				ans+=a[i].c1;
				d1++;
			}
			else if(a[i].c2>a[i].c1&&a[i].c2>a[i].c3&&d2<=n>>1)
			{
				ans+=a[i].c2;
				d2++;
			}
			else if(a[i].c3>a[i].c1&&a[i].c3>a[i].c2&&d3<=n>>1)
			{
				ans+=a[i].c3;
				d3++;
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
