#include <bits/stdc++.h>
using namespace std;

struct club
{
	int x,y,z;
};
club a[100010];

int d[100010][4] = {0};

bool cmp1(club x,club y)
{
	return x.x - max(x.y,x.z) > y.x - max(y.y,y.z);
}

bool cmp2(club x,club y)
{
	return x.y - max(x.x,x.z) > y.y - max(y.z,y.x);
}

bool cmp3(club x,club y)
{
	return x.z - max(x.y,x.x) > y.z - max(y.y,y.x);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while (t--)
	{
		int ans = 0;
		int n;
		scanf("%d",&n);
		for (int i = 1;i <= n;i++)
		{
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
		}
		sort(a + 1,a + 1 + n,cmp1);
		int happy = 0;
		for (int i = 1;i <= n / 2;i++)
		{
			happy += a[i].x;
		}
		for (int i = n / 2 + 1;i <= n;i++)
		{
			happy += max(a[i].y,a[i].z);
		}
		ans = max(happy,ans);
		happy = 0;
		sort(a + 1,a + 1 + n,cmp2);
		for (int i = 1;i <= n / 2;i++)
		{
			happy += a[i].y;
		}
		for (int i = n / 2 + 1;i <= n;i++)
		{
			happy += max(a[i].x,a[i].z);
		}
		ans = max(happy,ans);
		happy = 0;
		sort(a + 1,a + 1 + n,cmp3);
		for (int i = 1;i <= n / 2;i++)
		{
			happy += a[i].z;
		}
		for (int i = n / 2 + 1;i <= n;i++)
		{
			happy += max(a[i].y,a[i].x);
		}
		ans = max(happy,ans);
		printf("%d\n",ans);
	}
	return 0;
}
