#include<bits/stdc++.h>
using namespace std;
struct peo
{
	int l1,l2,l3;
	int f=0;
}a[100010];
int n,b1,b2,b3,ans;
bool cmp1(peo a,peo b)
{
	return a.l1>b.l1;
}
bool cmp2(peo a,peo b)
{
	return a.l2>b.l2;
}
bool cmp3(peo a,peo b)
{
	return a.l3>b.l3;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		b1=0;
		b2=0;
		b3=0;
		ans=0;
		for(int i=0;i<100010;i++)
		{
			a[i].l1=0;
			a[i].l2=0;
			a[i].l3=0;
			a[i].f=0;
		}
		cin>>n;
		for(int i=0;i<n;i++)cin>>a[i].l1>>a[i].l2>>a[i].l3;
		
		sort(a,a+n,cmp1);
		for(int i=0;i<n;i++)
		{
			if(b1>=n/2)break;
			if(a[i].l1<a[i].l2||a[i].l1<a[i].l3||a[i].f!=0)continue;
			b1++;
			a[i].f=1;
			ans+=a[i].l1;
		}
		
		sort(a,a+n,cmp2);
		for(int i=0;i<n;i++)
		{
			if(b2>=n/2)break;
			if(a[i].l2<a[i].l1||a[i].l2<a[i].l3||a[i].f!=0)continue;
			b2++;
			a[i].f=1;
			ans+=a[i].l2;
		}
		
		sort(a,a+n,cmp3);
		for(int i=0;i<n;i++)
		{
			if(b3>=n/2)break;
			if(a[i].l3<a[i].l2||a[i].l3<a[i].l1||a[i].f!=0)continue;
			b3++;
			a[i].f=1;
			ans+=a[i].l3;
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
