#include <iostream>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		int a[n][4],cnt1=0,cnt2=0,cnt3=0,ans=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d %d %d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][3]>a[i][2]&&a[i][3]>a[i][1])
			{
				cnt3++;
			}
			if(a[i][3]>a[i][2]&&a[i][1]>a[i][2])
			{
				cnt2++;
			}
			if(a[i][1]>a[i][2]&&a[i][1]>a[i][3])
			{
				cnt1++;
			}
		}
		for(int i=0;i<n;i++)
		{
			ans+=a[i][1];
		}
		printf("%d\n",ans/2);
	}
	return 0;
} 
