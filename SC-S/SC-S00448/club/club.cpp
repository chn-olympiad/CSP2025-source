#include<bits/stdc++.h>
using namespace std;
struct A{
	int m1,m2,m3;
}a[100005];
int n;
int c1[100005],c2[100005],c3[100005];
int s1,s2,s3;
long long ans;
bool cmp12(int x,int y)
{
	return (a[x].m1-a[x].m2)<(a[y].m1-a[y].m2);
}
bool cmp13(int x,int y)
{
	return (a[x].m1-a[x].m3)<(a[y].m1-a[y].m3);
}
bool cmp21(int x,int y)
{
	return (a[x].m2-a[x].m1)<(a[y].m2-a[y].m1);
}
bool cmp23(int x,int y)
{
	return (a[x].m2-a[x].m3)<(a[y].m2-a[y].m3);
}
bool cmp31(int x,int y)
{
	return (a[x].m3-a[x].m1)<(a[y].m3-a[y].m1);
}
bool cmp32(int x,int y)
{
	return (a[x].m3-a[x].m2)<(a[y].m3-a[y].m2);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].m1>>a[i].m2>>a[i].m3;
			if(a[i].m1>=a[i].m2)
			{
				if(a[i].m1>=a[i].m3)
				{
					s1++;
					c1[s1]=i;
					ans=ans+a[i].m1;
				}
			}
			if(a[i].m2>=a[i].m1)
			{
				if(a[i].m2>=a[i].m3)
				{
					s2++;
					c2[s2]=i;
					ans=ans+a[i].m2;
				}
			}
			if(a[i].m3>=a[i].m2)
			{
				if(a[i].m3>=a[i].m1)
				{
					s3++;
					c3[s3]=i;
					ans=ans+a[i].m3;
				}
			}
		}
		if(s1>(n/2))
		{
			int t=s1-(n/2);
			int t1[t+5];
			int t2[t+5];
			sort(c1+1,c1+s1+1,cmp12);
			for(int i=1;i<=t;i++)
			{
				t1[i]=c1[i];
			}
			sort(c1+1,c1+s1+1,cmp13);
			for(int i=1;i<=t;i++)
			{
				t2[i]=c1[i];
			}
			for(int i=1;i<=t;i++)
			{
				if(a[t1[i]].m2-a[t1[i]].m1>a[t2[i]].m3-a[t2[i]].m1)
				{
					ans=ans-a[t1[i]].m1+a[t1[i]].m2;
				}
				else
				{
					ans=ans-a[t2[i]].m1+a[t2[i]].m3;
				}
			}
		}
		if(s2>(n/2))
		{
			int t=s2-(n/2);
			int t1[t+5];
			int t2[t+5];
			sort(c2+1,c2+s2+1,cmp21);
			for(int i=1;i<=t;i++)
			{
				t1[i]=c2[i];
			}
			sort(c2+1,c2+s2+1,cmp23);
			for(int i=1;i<=t;i++)
			{
				t2[i]=c2[i];
			}
			for(int i=1;i<=t;i++)
			{
				if(a[t1[i]].m1-a[t1[i]].m2>a[t2[i]].m3-a[t2[i]].m2)
				{
					ans=ans-a[t1[i]].m2+a[t1[i]].m1;
				}
				else
				{
					ans=ans-a[t2[i]].m2+a[t2[i]].m3;
				}
			}
		}
		if(s3>(n/2))
		{
			int t=s3-(n/2);
			int t1[t+5];
			int t2[t+5];
			sort(c3+1,c3+s3+1,cmp31);
			for(int i=1;i<=t;i++)
			{
				t1[i]=c3[i];
			}
			sort(c3+1,c3+s3+1,cmp32);
			for(int i=1;i<=t;i++)
			{
				t2[i]=c3[i];
			}
			for(int i=1;i<=t;i++)
			{
				if(a[t1[i]].m1-a[t1[i]].m3>a[t2[i]].m2-a[t2[i]].m3)
				{
					ans=ans-a[t1[i]].m3+a[t1[i]].m1;
				}
				else
				{
					ans=ans-a[t2[i]].m3+a[t2[i]].m2;
				}
			}
		}
		cout<<ans<<"\n";
		for(int i=1;i<=s1;i++)
		{
			c1[i]=0;
		}
		s1=0;
		for(int i=1;i<=s2;i++)
		{
			c2[i]=0;
		}
		s2=0;
		for(int i=1;i<=s3;i++)
		{
			c3[i]=0;
		}
		s3=0;
		for(int i=1;i<=n;i++)
		{
			a[i].m1=0;
			a[i].m2=0;
			a[i].m3=0;
		}
		ans=0;
	}
	return 0;
}