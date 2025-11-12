#include<bits/stdc++.h>
using namespace std;
struct node
{
	int a1,a2,a3;
} a[100005];
struct node2
{
	int id,cha;
	int cha2;
} b1[100005],b2[100005],b3[100005];
int n;
bool cmp2(const node2 &t3,const node2 &t4)
{
	return t3.cha<t4.cha;
}
bool cmp3(const node2 &t5,const node2 &t6)
{
	return min(t5.cha,t5.cha2)<min(t6.cha,t6.cha2);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		memset(b1,0,sizeof(b1));
		memset(b2,0,sizeof(b2));
		memset (b3,0,sizeof(b3));
		cin>>n;
		for(int i=1; i<=n; i++)
		{
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
		}
		int cnt1=0;
		int cnt2=0;
		int cnt3=0;
		int ans=0;
		for(int i=1; i<=n; i++)
		{
			if(a[i].a1>=a[i].a2&&a[i].a1>=a[i].a3)
			{
				cnt1++;
				b1[cnt1].id=i;
				ans+=a[i].a1;
			}
			else if(a[i].a2>=a[i].a1&&a[i].a2>=a[i].a3)
			{
				cnt2++;
				b2[cnt2].id=i;
				ans+=a[i].a2;
			}
			else
			{
				cnt3++;
				b3[cnt3].id=i;
				ans+=a[i].a3;
			}
		}
		if(cnt1>n/2)
		{
			for(int i=1; i<=cnt1; i++)
			{
				b1[i].cha=a[b1[i].id].a1-a[b1[i].id].a2;
				b1[i].cha2=a[b1[i].id].a1-a[b1[i].id].a3;
			}
			sort(b1+1,b1+1+cnt1,cmp3);
			for(int i=1; i<=cnt1-n/2; i++)
			{

				ans-=min(b1[i].cha,b1[i].cha2);
			}
		}
		if(cnt2>n/2)
		{
			for(int i=1; i<=cnt2; i++)
			{
				b2[i].cha=a[b2[i].id].a2-a[b2[i].id].a1;
				b2[i].cha2=a[b2[i].id].a2-a[b2[i].id].a3;
			}
			sort(b2+1,b2+1+cnt2,cmp3);
			for(int i=1; i<=cnt2-n/2; i++)
			{
				ans-=min(b2[i].cha,b2[i].cha2);
			}
		}
		if(cnt3>n/2)
		{
			for(int i=1; i<=cnt3; i++)
			{
				b3[i].cha=a[b3[i].id].a3-a[b3[i].id].a1;
				b3[i].cha2=a[b3[i].id].a3-a[b3[i].id].a2;
			}
			sort(b3+1,b3+1+cnt3,cmp3);
			for(int i=1; i<=cnt3-n/2; i++)
			{

				ans-=min(b3[i].cha,b3[i].cha2);
			}
		}
		cout<<ans<<endl;

	}
	return 0;

}
/*
1
30
7348 703 14149
11524 8584 12424
17146 10238 6221
11343 4548 12436
6734 16641 13734
9412 2951 16747
10457 5645 11050
8832 8638 15352
4359 3830 8631
6854 1555 17206
12210 4057 15760
2094 1772 3950
11792 4634 16269
12742 18687 2815
7616 1139 19916
11595 10431 12257
9859 2477 16696
15314 3789 19173
3331 351 18764
18198 13027 19770
11562 2215 13762
10233 490 18645
8216 497 17311
12545 5185 19009
14061 2936 18146
6223 3907 18331
18932 9546 2865
11326 7358 16023
1596 1197 4624
14531 8412 19487


*/
