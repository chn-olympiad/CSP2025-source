#include<bits/stdc++.h>
using namespace std;
int t;
long long sum1,sum2,sum3;
struct node
{
	int x1,x2,x3;
}a[100005];
int cmp1(node n,node m)
{
	if (n.x1!=m.x1)
		return n.x1>m.x1;
}
int cmp2(node n,node m)
{
	if (n.x2!=m.x2)
		return n.x2>m.x2;
}
int cmp3(node n,node m)
{
	if (n.x3!=m.x3)
		return n.x3>m.x3;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		int n;
		memset(a,0,sizeof(a));
		sum1=sum2=sum3=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d %d %d",&a[i].x1,&a[i].x2,&a[i].x3);
		}
		sort(a+1,a+n+1,cmp1);
		for(int i=1;i<=n/2;i++)
		{
			sum1+=a[i].x1;
		}
		for(int i=n/2+1;i<=n;i++)
		{
			sum1+=max(a[i].x2,a[i].x3);
		}
		sort(a+1,a+n+1,cmp2);
		for(int i=1;i<=n/2;i++)
		{
			sum2+=a[i].x2;
		}
		for(int i=n/2+1;i<=n;i++)
		{
			sum2+=max(a[i].x1,a[i].x3);
		}
		sort(a+1,a+n+1,cmp3);
		for(int i=1;i<=n/2;i++)
		{
			sum3+=a[i].x3;
		}
		for(int i=n/2+1;i<=n;i++)
		{
			sum3+=max(a[i].x2,a[i].x1);
		}
		printf("%d\n",max(sum1,max(sum2,sum3)));
	}
	return 0;
} 
