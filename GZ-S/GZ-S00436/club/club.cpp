//GZ-S00436 贵阳市南明区李端棻中学 邓景一 
#include<bits/stdc++.h>
using namespace std;
struct student
{
	int a1,a2,a3,f,x;
}s[100000],A1[100000],A2[1000000],A3[100000];
bool cmp1(student a,student b)
{
	return a.a1>b.a1;
}
bool cmp2(student a,student b)
{
	return a.a2>b.a2;
}
bool cmp3(student a,student b)
{
	return a.a3>b.a3;
}
bool cmp(int a,int b)
{
	return a>b;
}
int f(int x,int y,int z)
{
	int b[3];
	b[0]=x;b[1]=y;b[2]=x;
	sort(b,b+3);
	return b[2];
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	while(t--)
	{
		int ans=0;
		cin>>n;
		int most=n/2,x1=0,x2=0,x3=0;
		for(int i=1;i<=n;i++)
		{	
			cin>>s[i].a1>>s[i].a2>>s[i].a3;s[i].x=0;s[i].f=f(s[i].a1,s[i].a2,s[i].a3);
			if(s[i].a1!=0) x1=1;
			if(s[i].a2!=0) x2=1;
			if(s[i].a3!=0) x3=1;
		}
		if(x1==0 && x2==0)
		{
			sort(s+1,s+1+n,cmp3);
			for(int i=1;i<=most;i++)
				ans+=s[i].a3;
			cout<<ans;
			continue;
		}
		else if(x2==0 && x3==0)
		{
			sort(s+1,s+1+n,cmp1);
			for(int i=1;i<=most;i++)
				ans+=s[i].a1;
			cout<<ans;
			continue;
		}
		else if(x1==0 && x3==0)
		{
			sort(s+1,s+1+n,cmp2);
			for(int i=1;i<=most;i++)
				ans+=s[i].a2;
			cout<<ans;
			continue;
		}
		else
		{
			int y1=0,y2=0,y3=0;
			for(int i=1;i<=n;i++)
			{
				if(s[i].f==s[i].a1)
				{	A1[i]=s[i];y1++;}
				else if(s[i].f==s[i].a2)
				{	A2[i]=s[i];y2++;}
				else if(s[i].f==s[i].a3)
				{	A2[i]=s[i];y3++;}
			}
			sort(A1+1,A1+n+1,cmp1);
			for(int i=1;i<=most;i++)
				ans+=A1[i].a1;
			for(int i=most+1;i<=y1;i++)
			{
				if(A1[i].a2>A1[i].a3)
				{
					A2[y2+1]=A1[i];
					y2++;
				}
				else
				{
					A3[y3+1]=A1[i];
					y3++;
				}
			}
			sort(A2+1,A2+n+1,cmp2);
			for(int i=1;i<=most;i++)
				ans+=A2[i].a2;
			for(int i=most+1;i<=y2;i++)
			{
				A3[y3+1]=A2[i];
				y3++;
			}
			for(int i=1;i<=y3;i++)
				ans+=A3[i].a3;
			cout<<ans;
		}
	}
	return 0;
}
