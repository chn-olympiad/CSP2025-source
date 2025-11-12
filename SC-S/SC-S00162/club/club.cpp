#include<iostream>
#include<algorithm>
using namespace std;
struct cc1{
	int bian,val;
}c1[100005];
int cmp1(cc1 a,cc1 b)
{
	return a.val>b.val;
}
struct cc2{
	int bian,val;
}c2[100005];
int cmp2(cc2 a,cc2 b)
{
	return a.val>b.val;
}
struct cc3{
	int bian,val;
}c3[100005];
int cmp3(cc3 a,cc3 b)
{
	return a.val>b.val;
}
int flag[100005];
int n;
int now1=1,now2=1,now3=1,x1=0,x2=0,x3=0;
void die1()
{
	while (flag[x1]==1 && now1<=n)
	{
		now1++;
		x1=c1[now1].bian;
	}
	return ;
}
void die2()
{
	while (flag[x2]==1 && now2<=n)
	{
		if (x2==x1)
		{
			if (c2[now2].val+c1[now1+1].val>c1[now1].val+c2[now2+1].val) 
			{
				now1++;
				die1();
				break;
			}
		}
		now2++;
		x2=c2[now2].bian;
	}
	return ;
}
void die3()
{
	while (flag[x3]==1 && now3<=n)
	{
		if (x3==x1)
		{
			if (c3[now3].val+c1[now1+1].val>c1[now1].val+c3[now3+1].val) 
			{
				now1++;
				die1();
				break;
			}
		}
		if (x3==x3)
		{
			if (c3[now3].val+c2[now2+1].val>c2[now2].val+c3[now3+1].val) 
			{
				now2++;
				die2();
				break;
			}
		}
		now3++;
		x3=c3[now3].bian;
	}
	return ;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while (t--)
	{
		cin>>n;
		int ans=0;
		for (int i=1;i<=n;i++)
		{
			int x1,x2,x3;
			cin>>c1[i].val>>c2[i].val>>c3[i].val;
			c1[i].bian=i;
			c2[i].bian=i;
			c3[i].bian=i;
		}
		sort(c1+1,c1+n+1,cmp1);
		sort(c2+1,c2+n+1,cmp2);
		sort(c3+1,c3+n+1,cmp3);
		int ming1=n/2,ming2=n/2,ming3=n/2;
		for (int i=1;i<=n;i++)
		{
			x1=c1[now1].bian;
			x2=c2[now2].bian;
			x3=c3[now3].bian;
			die1();
			die2();
			die3();
			if (now1<=n && x1!=0 && flag[x1]!=1 && ming1) 
			{
				ans+=c1[now1].val;
				ming1--;
				flag[x1]=1;
				//cout<<"s1:"<<x1<<"\n";
			}
			if (now2<=n && x2!=0&& flag[x2]!=1  && ming2) 
			{
				ming2--;
				ans+=c2[now2].val;
				flag[x2]=1;
				//cout<<"s2:"<<x2<<"\n";
			}
			if (now3<=n && x3!=0&& flag[x3]!=1  && ming3) 
			{
				ming3--;
				ans+=c3[now3].val;
				flag[x3]=1;
				//cout<<"s3:"<<x3<<"\n";
			}
			now1++;
			now2++;
			now3++;
		 } 
		cout<<ans<<"\n";
		for (int i=1;i<=n;i++) flag[i]=0;
		now1=1;
		now2=1;
		now3=1;
	}
	return 0;
}