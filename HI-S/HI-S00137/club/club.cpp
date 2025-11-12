#include<bits/stdc++.h>
using namespace std;
int t,n,a1,a2,a3,b1;
//	priority_queue <int>q;
struct y
{
	int a,b,c,id;
}d[100005],p1[100005],p2[100005],p3[100005];
bool cmp1(y x,y x1)
{
	return x.a>=x1.a;
}
bool cmp2(y x,y x1)
{
	return x.b>=x1.b;
}
bool cmp3(y x,y x1)
{
	return x.c>=x1.c;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		a1=0;
		a2=0;
		a3=0;
		b1=0;
		for(int j=1;j<=n;j++)
		{
			cin>>d[j].a>>d[j].b>>d[j].c;
			d[j].id=j;
			if(d[j].a>=d[j].b && d[j].a>=d[j].c)
			{
				p1[++a1]=d[j];
				b1+=d[j].a;
			}
			else if(d[j].b>=d[j].a && d[j].b>=d[j].c)
			{
				p2[++a2]=d[j];
				b1+=d[j].b;
			}
			else if(d[j].c>=d[j].a && d[j].c>=d[j].b)
			{
				p3[++a3]=d[j];
				b1+=d[j].c;
			}
		}
		sort(p1+1,p1+1+a1,cmp1);
		sort(p2+1,p2+1+a2,cmp2);
		sort(p3+1,p3+1+a3,cmp3);
/*		for(int j=1;j<=a1;j++)cout<<p1[j].a<<" ";
		cout<<endl;
		for(int j=1;j<=a2;j++)cout<<p2[j].b<<" ";
		cout<<endl;
		for(int j=1;j<=a3;j++)cout<<p3[j].c<<" ";
		cout<<endl;*/
		int u=1;
		while(u)
		{
			for(int j=a1;j>=n/2+1;j--)
			{
				if(p1[j].b>=p1[j].c)
				{
					a2++;
					p2[a2]=p1[a1];
					b1+=p1[a1].b;
					b1-=p1[a1].a;
					a1--;
					
				}
				else
				{
					a3++;
					p3[a3]=p1[a1];
					b1+=p1[a1].c;
					b1-=p1[a1].a;
					a1--;
					
				}
			}
			for(int j=a2;j>=n/2+1;j--)
			{
				if(p2[j].a>=p2[j].c)
				{
					a1++;
					p1[a1]=p2[a2];
					b1+=p2[a2].a;
					b1-=p2[a2].b;
					a2--;
					
				}
				else
				{
					a3++;
					p3[a3]=p2[a2];
					b1+=p2[a2].c;
					b1-=p2[a2].b;
					a2--;
					
				}
			}
			for(int j=a3;j>=n/2+1;j--)
			{
				if(p3[j].b>=p3[j].a)
				{
					a2++;
					p2[a2]=p3[a3];
					b1+=p3[a3].b;
					b1-=p2[a2].c;
					a3--;
					
				}
				else
				{
					a1++;
					p1[a1]=p3[a3];
					b1+=p3[a3].a;
					b1-=p3[a3].c;
					a3--;
					
				}
			}
			if(a1<=n/2 && a2<=n/2 && a3<=n/2)u=0;
		}
		cout<<b1<<endl;//<<"1/";
/*		for(int j=1;j<=a1;j++)cout<<p1[j].a<<" ";
		cout<<endl<<"2/";
		for(int j=1;j<=a2;j++)cout<<p2[j].b<<" ";
		cout<<endl<<"3/";
		for(int j=1;j<=a3;j++)cout<<p3[j].c<<" ";
		cout<<endl;*/
	}
	return 0;
 } 
