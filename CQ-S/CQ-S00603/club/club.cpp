#include<bits/stdc++.h>
using namespace std;
int a[100005];
int b[100005];
int c[100005];
int d[100005];
int e[100005];
bool cmp1(int x,int y)
{
	return d[x]>d[y];
}
priority_queue<int> f,g;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,ans=0;
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d%d%d",&a[i],&b[i],&c[i]);
		for(int i=1;i<=n;i++)
		{
			d[i]=max(b[i],c[i])-a[i];
			e[i]=i; 
			ans+=a[i];
		}
		sort(e+1,e+1+n,cmp1);
		while(!f.empty())f.pop();
		while(!g.empty())g.pop();
		for(int i=1;i<=n/2;i++)
		{
			if(b[e[i]]>c[e[i]])f.push(c[e[i]]-b[e[i]]);
			else g.push(b[e[i]]-c[e[i]]);
			ans+=d[e[i]];
		}
		for(int i=n/2+1;i<=n&&d[e[i]]>0;i++)
		{
			if(b[e[i]]>c[e[i]]&&f.size()<n/2)
			{
				f.push(c[e[i]]-b[e[i]]);
				ans+=d[e[i]];
				continue;
			}
			if(c[e[i]]>b[e[i]]&&g.size()<n/2)
			{
				g.push(b[e[i]]-c[e[i]]);
				ans+=d[e[i]];
				continue;
			}
			int cnt=0,sum=0;
			if(f.size()<n/2&&b[e[i]]-a[e[i]]>sum)cnt=1,sum=b[e[i]]-a[e[i]];
			if(g.size()<n/2&&c[e[i]]-a[e[i]]>sum)cnt=2,sum=c[e[i]]-b[e[i]];
			if(f.size()==n/2&&f.top()+b[e[i]]-a[e[i]]>sum)cnt=3,sum=f.top()+b[e[i]]-a[e[i]];
			if(g.size()==n/2&&g.top()+c[e[i]]-a[e[i]]>sum)cnt=4,sum=g.top()+c[e[i]]-a[e[i]];
			ans+=sum;
			if(cnt==1)f.push(c[e[i]]-b[e[i]]);
			if(cnt==2)g.push(b[e[i]]-c[e[i]]);
			if(cnt==3)f.pop(),f.push(c[e[i]]-b[e[i]]);
			if(cnt==4)g.pop(),g.push(b[e[i]]-c[e[i]]);
		}
		printf("%d\n",ans);
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

147325
125440
152929
150176
158541
*/
