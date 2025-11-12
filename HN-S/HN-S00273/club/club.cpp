#include<bits/stdc++.h>
using namespace std;
int n,t;
struct node{
	int a1,a2,a3;
	bool f=0;
}a[100005];
bool cmp(node x,node y)
{
	return x.a1>y.a1;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		int ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			a[i].a1=0;
			a[i].a2=0;
			a[i].a3=0;
			a[i].f=0;
		}
		for(int i=1;i<=n;i++)
			scanf("%d%d%d",&a[i].a1,&a[i].a2,&a[i].a3);
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n/2;i++)
			ans+=a[i].a1;
		cout<<ans<<endl;
	}
	return 0;
}
