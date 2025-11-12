#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int aclub[100005];
int bclub[100005];
int cclub[100005];
int which[100005];
int adjustment[100005];
int total;
int ans;
int cnt;
int num;
int great;
int limitation;
int alike,blike,clike;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);	
	cin>>total;
	while(total--)
	{
		ans=0,alike=blike=clike=0;
		cnt=1;
		cin>>num;
		limitation=(num/2);
		for(int i=1;i<=num;i++)
		{
			cin>>aclub[i]>>bclub[i]>>cclub[i];
			great=max(aclub[i],max(bclub[i],cclub[i]));
			if(great==aclub[i])
			{
					ans+=great;
					alike++;
					which[i]=1;
			}
			if(great==bclub[i])
			{
				ans+=great;
				blike++;
				which[i]=2;
			}
			if(great==cclub[i])
			{
				ans+=great;
				clike++;
				which[i]=3;
			}
		}
		//a
		if(alike>limitation)
		{
			for(int i=1;i<=num;i++)
			{
				if(which[i]==1)
				{
					adjustment[cnt]=aclub[i]-max(bclub[i],cclub[i]);
					cnt++;
				}
			}
			sort(adjustment,adjustment+alike+1);
			for(int i=1;i<=alike-limitation;i++)
				{
					ans-=adjustment[i];
				}
		}
		//b
		else if(blike>limitation)
		{
			for(int i=1;i<=num;i++)
			{
				if(which[i]==2)
				{
					adjustment[cnt]=bclub[i]-max(aclub[i],cclub[i]);
					cnt++;
				}
			}
			sort(adjustment,adjustment+blike+1);
			for(int i=1;i<=blike-limitation;i++)
				{
					ans-=adjustment[i];
				}
		}
		//c
		else if(clike>limitation)
		{
			for(int i=1;i<=num;i++)
			{
				if(which[i]==3)
				{
					adjustment[cnt]=cclub[i]-max(aclub[i],bclub[i]);
					cnt++;
				}
			}
			sort(adjustment,adjustment+clike+1);
			for(int i=1;i<=clike-limitation;i++)
				{
					ans-=adjustment[i];
				}
		}
		cout<<ans<<endl;
		for(int i=0;i<=num;i++)
			{
				aclub[i]=0;
				bclub[i]=0;
				cclub[i]=0;
				which[i]=0;
				adjustment[i]=0;
			}
	}
	return 0;
}
