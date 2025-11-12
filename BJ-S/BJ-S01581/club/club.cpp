#include<bits/stdc++.h>
using namespace std;
int n,T,num1,num2,num3;
long long maxx;
struct node
{
	int x,y,z;
}a[100005],b[100005],c[100005];
bool cmp1(node x,node y)
{
	return max(x.y,x.z)>max(y.y,y.z);
}
bool cmp2(node x,node y)
{
	return max(x.x,x.z)>max(y.x,y.z);
}
bool cmp3(node x,node y)
{
	return max(x.y,x.x)>max(y.y,y.x);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		num1=num2=num3=maxx=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			if(x==max(x,max(y,z)))
			{
				num1++;
				a[num1].y=y-x;
				a[num1].z=z-x;
			}
			else if(y==max(x,max(y,z)))
			{
				num2++;
				b[num2].x=x-y;
				b[num2].z=z-y;
			}
			else
			{
				num3++;
				c[num3].x=x-z;
				c[num3].y=y-z;
			}
			maxx+=max(x,max(y,z));
		}
		if(num1>n/2)
		{
			sort(a+1,a+num1+1,cmp1);
			for(int i=1;i<=num1-n/2;i++) maxx+=max(a[i].y,a[i].z);
		}
		else if(num2>n/2)
		{
			sort(b+1,b+num2+1,cmp2);
			for(int i=1;i<=num2-n/2;i++) maxx+=max(b[i].x,b[i].z);
		}
		else if(num3>n/2)
		{
			sort(c+1,c+num3+1,cmp3);
			for(int i=1;i<=num3-n/2;i++) maxx+=max(c[i].y,c[i].x);
		}
		printf("%lld\n",maxx);
	}
	return 0;
}
