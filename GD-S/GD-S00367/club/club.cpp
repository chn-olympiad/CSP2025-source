#include<bits/stdc++.h>
using namespace std;
const int N=100005;
struct node{
	int a,b,c,bj;
}my[N];
bool cmp1(node aa,node bb)
{
	return aa.a>bb.a;
}
bool cmp2(node aa,node bb)
{
	if(aa.a==bb.a) return aa.b>bb.b;
	else return aa.a>bb.a;
}
bool cmp3(node aa,node bb)
{
	return aa.c>bb.c;
}
int bj(int a,int b,int c)
{
	if(a>=b)
	{
		if(a>=c) return a;
		else return c;
	}  
}
int T,n;
priority_queue<int>q1;
priority_queue<int>q2;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		
		int ans=0,s[5],p1,p2,p3;
		memset(s,0,sizeof(s));
		cin>>n;
		int nn=n/2,c1=0,c2=0,c3=0;
		for(int i=1;i<=n;i++)
		{
			cin>>my[i].a>>my[i].b>>my[i].c;
			c2+=my[i].b;
			c3+=my[i].c;
		}
		if(c2==c3&&c3==0)
		{
			sort(my+1,my+n+1,cmp1);
			for(int i=1;i<=n/2;i++)
				ans+=my[i].a;
			cout<<ans<<"\n";
		}
		if(c3==0)
		{
//			sort(my+1,my+n+1,cmp2);
			for(int i=1;i<=n;i++)
			{
				if(my[i].a>my[i].b)
				{
					if(s[1]==nn)
					{
						if(my[i].a>q1.top()) 
						{
							ans+=my[i].a;
							ans-=q1.top();
							q1.pop();
						}
					}
					else
					{
						ans+=my[i].a;
					s[1]++;
					q1.push(my[i].a);
					}
					
				}
				else 
				{
					if(s[2]==nn)
					{
						
						if(my[i].b>q2.top()) 
						{
							ans+=my[i].b;
							ans-=q2.top();
							q2.pop();
						}
					}
					else
					{
						ans+=my[i].b;
					s[2]++;
					q2.push(my[i].b);
					}
					
				}
			}
			cout<<ans<<"\n";
		}
		if(c2!=0&&c3!=0)
		{
			for(int i=1;i<=n;i++)
			{
				if(my[i].a>=my[i].b&&my[i].a>=my[i].c)
				{
					if(s[1]==nn)
					{
						if(my[i].b>my[i].c) 
						{
							p2=i,ans+=my[i].b;
						}
						else p3=i,ans+=my[i].c;
					}
					else
					{
						ans+=my[i].a;
						p1=i;
						s[1]++;
					}
					
				}
				if(my[i].a<=my[i].b&&my[i].b>=my[i].c)
				{
					if(s[2]==nn)
					{
						if(my[i].a>my[i].c) ans+=my[i].a;
						else ans+=my[i].c;
					}
					ans+=my[i].b;
					s[2]++;
				}
				if(my[i].c>=my[i].a&&my[i].b<=my[i].c)
				{
					if(s[3]==nn)
					{
						if(my[i].a>my[i].b) ans+=my[i].a;
						else ans+=my[i].b;
					}
					ans+=my[i].c;
					s[3]++;
				}
	//			cout<<ans<<"\n";
			}
			cout<<ans<<"\n";
		}
	
	}
	return 0;
}
