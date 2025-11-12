#include<bits/stdc++.h>
using namespace std;
int n,T;
long long ans;
int a[100001],b[100001],c[100001];
int la,lb,lc;
bool cmp(pair<int,int> x,pair<int,int> y)
{
	return x.first>y.first;
}
bool cmpp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		ans=0;
		scanf("%d",&n);
		la=0;
		lb=0;
		lc=0;
		for(int i=1;i<=n;i++)
		{
			pair<int,int> s[4];
			scanf("%d %d %d",&s[1].first,&s[2].first,&s[3].first);
			s[1].second=1;s[2].second=2;s[3].second=3;
			sort(s+1,s+4,cmp);
			ans=ans+s[1].first;
			switch(s[1].second)
			{
				case 1:
					{
						la++;
						a[la]=(int)(s[2].first-s[1].first);
						break;
					}
				case 2:
					{
						lb++;
						b[lb]=(s[2].first-s[1].first);
						break;
					}
				case 3:
					{
						lc++;
						c[lc]=(s[2].first-s[1].first);
						break;
					}
			}
		}
		if(la>n/2)
		{
			sort(a+1,a+1+la,cmpp);
			//for(int i=1;i<=la;i++) printf("a[%d]=%d\n",i,a[i]);
			for(int i=1;i<=la-n/2;i++)
			{
				ans=ans+a[i];
				//printf("1,ans=%d\n",ans);
			}
		}
		if(lb>n/2)
		{
			sort(b+1,b+1+lb,cmpp);
			//for(int i=1;i<=lb;i++) printf("b[%d]=%d\n",i,b[i]);
			for(int i=1;i<=lb-n/2;i++)
			{
				ans=ans+b[i];
				//printf("2,ans=%d\n",ans);
			}
		}
		if(lc>n/2)
		{
			sort(c+1,c+1+lc,cmpp);
			//for(int i=1;i<=lc;i++) printf("c[%d]=%d\n",i,c[i]);
			for(int i=1;i<=lc-n/2;i++)
			{
				ans=ans+c[i];
				//printf("3,ans=%d\n",ans);
			}
		}
		printf("%lld\n",ans);
		//printf("--------------------------------------\n");
	}
}
/*
本题思路：
首先把所有人的最高意愿值累加，然后把多余的人中期望差小的滑档 
希望100pts，签到题别给我炸了 QAQ 
*/
//I think I may be 3~2=
//QAQ
//freeopen(免费开启) 
//froepen
//freopen
//zto 大佬们 orz 
