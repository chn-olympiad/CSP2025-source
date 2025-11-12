#include <bits/stdc++.h>
using namespace std;
struct _
{
	int data,num;
}a[100010][4];
bool cmp(_ x,_ y)
{
	if(x.data==y.data)
	{
		return x.num<y.num;
	}
	return x.data>y.data;
}
int p[4],n,b[100010];
bool a0(int x)
{
	for(int i=1;i<=n;i++)
	{
		if(a[i][x].data!=0)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(p,0,sizeof(p));
		int sum=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			_ x,y,z;
			scanf("%d%d%d",&x.data,&y.data,&z.data);
			x.num=1,y.num=2,z.num=3;
			b[i]=x.data;
			a[i][1]=x;
			a[i][2]=y;
			a[i][3]=z;
		}
		if(a0(2) && a0(3))
		{
			int sum=0;
			sort(b+1,b+n+1);
			for(int i=n;i>n/2+1;i--)
			{
				sum+=b[i];
			}
			printf("%d\n",sum);
		}
		else
		{
			for(int i=n;i>=1;i--)
			{
				sort(a[i]+1,a[i]+4,cmp);
				if(p[a[i][1].num]<n/2)
				{
					sum+=a[i][1].data;
					p[a[i][1].num]++;
				}
				else
				{
					sum+=a[i][2].data;
					p[a[i][2].num]++;
				}
			}
			printf("%d\n",sum);
		}
	}
	
	return 0;
}