#include<bits/stdc++.h>
using namespace std;
int t,n,sum,aa,bb,cc,acc;
const int N=1e5+10;
struct stu{
	int a,b,c,f1,f2,f3;
}sati[N];
bool cmp(stu x,stu y)
{
	if(x.a==y.a)return x.b>y.b;
	return x.a>y.a;	
}
//int Max(int j)
//{
//	if(sati[j].a>=sati[j].b&&sati[j].a>=sati[j].c)return sati[j].a;
//		else if(sati[j].b>=sati[j].a&&sati[j].b>=sati[j].c)return sati[j].b;
//		else if(sati[j].c>=sati[j].a&&sati[j].c>=sati[j].b)return sati[j].c;
//}
bool check1()
{
	sum=0;
		for(int j=0;j<n;j++)
		{
			if(sati[j].a>=sati[j].b&&sati[j].a>=sati[j].c)
			{
				sum+=sati[j].a;aa++;
			}
			else if(sati[j].b>=sati[j].a&&sati[j].b>=sati[j].c)
			{
				sum+=sati[j].b;bb++;
			}
			else if(sati[j].c>=sati[j].a&&sati[j].c>=sati[j].b)
			{
				sum+=sati[j].c;cc++;
			}
		}
			if(aa<=(n/2)&&bb<=(n/2)&&cc<=(n/2))return 1;
			else return 0;
			
}
void check2()
{
	sum=0;
	sort(sati,sati+n,cmp);
	for(int j=1;j<n;j++)
	{
//		int MAX=Max(j);
//		if(aa)
//		if(aa+1<=(n/2)){sati[j].f1+=sati[j-1].a;aa++;}
//		if(bb+1<=(n/2)){sati[j].f2+=sati[j-1].a;aa++;}
		if(aa+1<=(n/2))sum+=sati[j].a;
		else sum+=sati[j].b;
	
			
	}
}
void check3()
{
		sum=0;
		int aaa=max(sati[0].a+sati[1].b,sati[0].a+sati[1].c);
		int bbb=max(sati[0].b+sati[1].a,sati[0].b+sati[1].c);
		if(aaa>=bbb)sum=aaa;
		else sum=bbb;
		int ccc=max(sati[0].c+sati[1].a,sati[0].c+sati[1].a);
		if(ccc>=sum)sum=ccc;
	}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d",&n);
		for(int j=0;j<n;j++)
		{
			scanf("%d%d%d",&sati[j].a,&sati[j].b,&sati[j].c);
			if(sati[j].c!=0)acc=-1;
		}
		//最大值即可成立 
			if(check1())printf("%d\n",sum);
			else if(acc!=-1)
			{
				check2();printf("%d\n",sum);
			}
			else if(n==2)
			{
				check3();printf("%d\n",sum);
			}
	}
//	for(int i=0;i<t;i++)
//		printf("%d %d %d %d\n",n,sati[i].a,sati[i].b,sati[i].c);

	return 0;
}
