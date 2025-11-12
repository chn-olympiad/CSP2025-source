//GZ-S00142 贵阳市第二实验中学 岑钰欣 
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct person
{
	int m1,m2,m3,k=0;
}p[100000];
bool cmp1(person a,person b)
{
	return a.m1>b.m1;
}
bool cmp2(person a,person b)
{
	return a.m2>b.m2;
}
bool cmp3(person a,person b)
{
	return a.m3>b.m3;
}
int he1(int n)
{
	int a=0;
	for(int i=0;i<n/2;i++)
	{
		a=p[i].m1+a;
	}
	return a;
}
int he2(int n)
{
	int b=0;
	for(int i=0;i<n/2;i++)
	{
		b+=p[i].m2;
	}
	return b;
}
int he3(int n)
{
	int c=0;
	for(int i=0;i<n/2;i++)
	{
		c+=p[i].m3;
	}
	return c;
}


int He2(int n)
{
	int b=0;
	for(int i=0;i<n;i++)
	{
		b+=p[i].m2;
	}
	return b;
}
int He3(int n)
{
	int c=0;
	for(int i=0;i<n;i++)
	{
		c+=p[i].m3;
	}
	return c;
}
int zhuida(int a,int b,int c,int n)
{
	int max=a;
	if(max<b)max=b;
	if(max<c)max=c;	
	if(b==c&&max<b) 
	{
	int b1=He2(n);
	int c1=He3(n);
	if(c1>b1)max=c;	
	}
	return max;
}
void shanchu(int m,int a,int b,int c,int n)
{
	if(m==a)
	{
		sort(p,p+n,cmp1);
		p[0].m2=0;
		p[0].m3=0;
		p[1].m2=0;
		p[1].m3=0;
	}
	if(m==b)
	{
		sort(p,p+n,cmp2);
		p[0].m2=0;
		p[0].m3=0;
		p[1].m2=0;
		p[1].m3=0;
	}
	if(m==c)
	{
		sort(p,p+n,cmp3);
		p[0].m2=0;
		p[0].m3=0;
		p[1].m2=0;
		p[1].m3=0;
	}
		
	for(int i=0;i<n;i++)
	{
		if(m==a)
		{
			p[i].m1=0;
		}
		if(m==b)
		{
			p[i].m2=0;
		}
		if(m==c)
		{
			p[i].m3=0;
		}
	}
}
int main(int argc, char** argv) 
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,a,b,c,max1,max2,max3,max4;
	scanf("%d",&t);
	for (int i=1;i<=t;i++)
	{   int m=0;
		max1=0;
		max2=0;
		max3=0;
		scanf("%d",&n);
		p[n];
		for(int j=0;j<n;j++)
		{
			scanf("%d%d%d",&p[j].m1,&p[j].m2,&p[j].m3);
			if((p[j].m1==0&&p[j].m2!=0&&p[j].m3!=0)||(p[j].m1!=0&&p[j].m2==0&&p[j].m3!=0)||(p[j].m1!=0&&p[j].m2!=0&&p[j].m3!=0))p[j].k=1;
			if((p[j].m1==0&&p[j].m2==0&&p[j].m3!=0)||(p[j].m1==0&&p[j].m2!=0&&p[j].m3==0)||(p[j].m1!=0&&p[j].m2==0&&p[j].m3==0))p[j].k=2;
		}
		for(int j=0;j<2;j++)
		{
			sort(p,p+n,cmp1);
			a=he1(n);
			sort(p,p+n,cmp2);
			b=he2(n);
			sort(p,p+n,cmp3);
			c=he3(n);
			max4=zhuida(a,b,c,n);
			shanchu(max4,a,b,c,n);
            m+=max4;
		}
        printf("%d\n",m);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
