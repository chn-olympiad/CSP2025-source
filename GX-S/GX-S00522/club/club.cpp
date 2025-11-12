#include<bits/stdc++.h>
using namespace std;
struct person
{
	int a,b,c,sum;
	bool p1=false,p2=false,p3=false;
}p[100010];
bool cmp(person a1,person a2)
{
	return a1.sum>a2.sum;
}
bool cmp1(person a1,person a2)
{
	return a1.a>a2.a;
}
bool cmp2(person a1,person a2)
{
	return a1.b>a2.b;
}
bool cmp3(person a1,person a2)
{
	return a1.c>a2.c;
}
void num()
{
	int n;
	unsigned long long u1=0,u2=0,u3=0;
	int b1=0,b2=0,b3=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i].a>>p[i].b>>p[i].c;
		p[i].sum=p[i].a+p[i].b+p[i].c;
	}
	sort(p+1,p+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		if(p[i].a>p[i].b&&p[i].a>p[i].c&&b1<n/2&&p[i].p1==false&&p[i].p2==false&&p[i].p3==false)
		{
			p[i].p1=true;
			u1+=p[i].a;
			b1++;
		}
		else if(p[i].b>p[i].a&&p[i].b>p[i].c&&b2<n/2&&p[i].p1==false&&p[i].p2==false&&p[i].p3==false)
		{	
			p[i].p2=true;
			u2+=p[i].b;
			b2++;
		}
		else if(p[i].c>p[i].b&&p[i].c>p[i].b&&b3<n/2&&p[i].p1==false&&p[i].p2==false&&p[i].p3==false)
		{
			p[i].p3=true;
			u3+=p[i].c;
			b3++;
		}
		else
		{
			if(b1<n/2)
			{
				b1++;
				u1+=p[i].a;
			}
			else if(b2<n/2)
			{
				b2++;
				u2+=p[i].b;
			}
			else if(b3<n/2)
			{
				b3++;
				u3+=p[i].c;
			}
		}
	}
	/*sort(p+1,p+n+1,cmp1);
	for(int i=n;i>=1;i--)
	{
		if(p[i].p1&&!p[i+1].p1)
		{
			if(p[i+1].p2)
			{
				if(p[i].a-p[i+1].a<abs(p[i].b-p[i+1].b))
				{
					p[i].p1=false;
					p[i+1].p1=true;
					u1-=p[i].a;
					u1+=p[i+1].a;
					p[i].p2=true;
					p[i+1].p2=false;
					u2-=p[i+1].b;
					u2+=p[i].b;
				}
			}
			else if(p[i+1].p3)
			{
				if(p[i].a-p[i+1].a<abs(p[i].c-p[i+1].c))
				{
					p[i].p1=false;
					p[i+1].p1=true;
					u1-=p[i].a;
					u1+=p[i+1].a;
					p[i].p3=true;
					p[i+1].p3=false;
					u3-=p[i+1].b;
					u3+=p[i].b;
				}
			}
		}
	}
	sort(p+1,p+n+1,cmp2);
	for(int i=n;i>=1;i--)
	{
		if(p[i].p2&&!p[i+1].p2)
		{
			if(p[i+1].p1)
			{
				if(p[i].b-p[i+1].b<abs(p[i].a-p[i+1].a))
				{
					p[i].p2=false;
					p[i+1].p2=true;
					u2-=p[i].b;
					u2+=p[i+1].b;
					p[i].p1=true;
					p[i+1].p1=false;
					u1-=p[i+1].b;
					u1+=p[i].b;
				}
			}
			else if(p[i+1].p3)
			{
				if(p[i].b-p[i+1].b<abs(p[i].c-p[i+1].c))
				{
					p[i].p2=false;
					p[i+1].p2=true;
					u2-=p[i].b;
					u2+=p[i+1].b;
					p[i].p3=true;
					p[i+1].p3=false;
					u3-=p[i+1].b;
					u3+=p[i].b;
				}
			}
		}
	}
	sort(p+1,p+n+1,cmp3);
	for(int i=n;i>=1;i--)
	{
		if(p[i].p3&&!p[i+1].p3)
		{
			if(p[i+1].p1)
			{
				if(p[i].c-p[i+1].c<abs(p[i].a-p[i+1].a))
				{
					p[i].p3=false;
					p[i+1].p3=true;
					u3-=p[i].a;
					u3+=p[i+1].a;
					p[i].p1=true;
					p[i+1].p1=false;
					u1-=p[i+1].b;
					u1+=p[i].b;
				}
			}
			else if(p[i+1].p2)
			{
				if(p[i].c-p[i+1].c<abs(p[i].b-p[i+1].b))
				{
					p[i].p3=false;
					p[i+1].p3=true;
					u1-=p[i].c;
					u1+=p[i+1].c;
					p[i].p2=true;
					p[i+1].p2=false;
					u2-=p[i+1].b;
					u2+=p[i].b;
				}
			}
		}
	}*/
	cout<<u1+u2+u3<<endl;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		num();
	}
	return 0;
}
