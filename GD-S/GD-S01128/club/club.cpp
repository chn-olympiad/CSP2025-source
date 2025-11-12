#include<iostream>
#include<algorithm>
using namespace std;
int n,t,ans;
struct node
{
	int a1,a2,a3;
}a[100005];
bool cmp(node x,node y)
{
	return x.a3>y.a3;
}
bool cmp1(node x,node y)
{
	return x.a2>y.a2;
}
bool cmp2(node x,node y)
{
	return x.a1>y.a1;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
		}
		sort(a+1,a+n+1,cmp);
		sort(a+1,a+n+1,cmp1);
		sort(a+1,a+n+1,cmp2);
		int x=0,y=0,z=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i].a1>=a[i].a2&&a[i].a1>=a[i].a3)
			{
				if(x<n/2)
				{
					x++;
					ans+=a[i].a1;
				}
			}
			else if(a[i].a2>=a[i].a1&&a[i].a2>=a[i].a3)
			{
				if(y<n/2)
				{
					y++;
					ans+=a[i].a2;
				}
			}
			else
			{
				if(z<n/2)
				{
					z++;
					ans+=a[i].a3;
				}
			}
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
} 
