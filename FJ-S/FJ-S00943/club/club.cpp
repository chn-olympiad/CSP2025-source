#include<bits/stdc++.h>
using namespace std;
struct node
{
	int a1,a2,a3;
	bool vis;
}a[100010];
bool cmp(node x,node y)
{
	return x.a1>y.a1;
}
bool cmp1(node x,node y)
{
	return x.a2>y.a2;
}
bool cmp2(node x,node y)
{
	return x.a3>y.a3;
}
int t,n;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i=0;i<n;i++)
		{
			cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
			a[i].vis=0;
		}
		int sum=0,ans1=0;
		sort(a,a+n,cmp);
		for (int i=0;sum<n/2&&i<n;i++)
			if (a[i].a1>=a[i].a2&&a[i].a1>=a[i].a3)
			{
				sum++;
				ans1+=a[i].a1;
				a[i].vis=1;
			}
		sort(a,a+n,cmp1);
		sum=0;
		for (int i=0;sum<n/2&&i<n;i++)
			if (a[i].a2>=a[i].a1&&a[i].a2>=a[i].a3&&!a[i].vis)
			{
				sum++;
				ans1+=a[i].a2;
				a[i].vis=1;
			}
		sort(a,a+n,cmp2);
		sum=0;
		for (int i=0;sum<n/2&&i<n;i++)
			if (a[i].a3>=a[i].a1&&a[i].a3>=a[i].a2&&!a[i].vis)
			{
				sum++;
				ans1+=a[i].a3;
				a[i].vis=1;
			}
		cout << ans1 << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
