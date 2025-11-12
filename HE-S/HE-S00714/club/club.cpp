#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int T;
struct stu
{
	int a,b,c;
	int clu;
}sd[maxn];
struct c
{
	int id;
	int cha;
}c1[maxn],c2[maxn],c3[maxn];
int n,num1,num2,num3,ans;
bool cmp1(c a,c b)
{
	return a.cha<b.cha;
}
bool cmp2(c a,c b)
{
	return a.cha<b.cha;
}
bool cmp3(c a,c b)
{
	return a.cha<b.cha;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--)
	{
		num1=num2=num3=0;
		ans=0;
		memset(sd,0,sizeof(sd));
		memset(c1,0,sizeof(c1));
		memset(c2,0,sizeof(c2));
		memset(c3,0,sizeof(c3));
		cin>>n;
		for (int i=1;i<=n;++i)
		{
			cin>>sd[i].a>>sd[i].b>>sd[i].c;
			if (sd[i].a>=sd[i].b&&sd[i].a>=sd[i].c&&!sd[i].clu)
			{
				ans+=sd[i].a;
				num1++,sd[i].clu=1;
				if (sd[i].b>sd[i].c) c1[num1].cha=sd[i].a-sd[i].b,c1[num1].id=2;
				else c1[num1].cha=sd[i].a-sd[i].c,c1[num1].id=3;
			}
			else if (sd[i].b>=sd[i].a&&sd[i].b>=sd[i].c&&!sd[i].clu)
			{
				ans+=sd[i].b;
				num2++,sd[i].clu=2;
				if (sd[i].a>sd[i].c) c2[num2].cha=sd[i].b-sd[i].a,c2[num2].id=1;
				else c2[num2].cha=sd[i].b-sd[i].c,c2[num2].id=3;
			}
			else if (sd[i].c>=sd[i].a&&sd[i].c>=sd[i].b&&!sd[i].clu)
			{
				ans+=sd[i].c;
				num3++,sd[i].clu=3;
				if (sd[i].a>sd[i].b) c3[num3].cha=sd[i].c-sd[i].a,c2[num2].id=1;
				else c3[num3].cha=sd[i].c-sd[i].b,c3[num3].id=2;
			}
		}	
		if (num1<=n/2&&num2<=n/2&&num3<=n/2) 
		{
			cout<<ans<<"\n";
			continue;	
		}
		else 
		{
			if (num1>n/2) 
			{
				sort(c1+1,c1+num1+1,cmp1);
				for (int i=1;i<=num1-n/2;++i) ans-=c1[i].cha;
				cout<<ans<<"\n";
			}
			else if (num2>n/2)
			{
				sort(c2+1,c2+num2+1,cmp2);
				for (int i=1;i<=num2-n/2;++i) ans-=c2[i].cha;
				cout<<ans<<"\n";
			}
			else if (num3>n/2)
			{
				sort(c3+1,c3+num3+1,cmp3);
				for (int i=1;i<=num3-n/2;++i) ans-=c3[i].cha;
				cout<<ans<<"\n";
			}
		}
	}
	return 0;
}
/*
5
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926
10
5491 4476 6362
9805 9130 15480
9090 9901 10480
6326 6516 1985
9119 2924 6420
9826 12689 7592
7293 16544 12901
11905 18183 18712
9015 3463 13025
1792 2433 17042
10
3004 4255 17336
11894 5756 17092
8150 14715 10991
5149 16652 16780
11524 11996 5433
7690 10472 19935
1184 6516 9246
3231 5570 10010
8426 16992 4654
18955 13977 16657
10
6839 5455 15586
11767 12919 2643
13775 8904 19938
13717 11997 15170
13707 2404 17497
3471 2462 8073
18467 14346 18663
13582 4839 15785
11875 7476 12308
8568 3134 18522
10
14230 3941 18854
12173 19429 15426
10974 4717 15290
4732 6608 4961
13198 13925 2137
10688 3092 16965
5356 19920 1471
11299 10796 13511
17932 12143 16407
5611 8100 16107
*/
