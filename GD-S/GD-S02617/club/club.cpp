#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,an;
const int N=100005;
int n,sa,sb,sc;
struct ren
{
	int a,b,c,d;
}nn[N];
int maxx(int j)
{
	int maxxx=max(nn[j].a,max(nn[j].b,nn[j].c));
	return (maxxx==nn[j].a?1:(maxxx==nn[j].b?2:3));
}
bool cmpa(ren A,ren B)
{
	return min(abs(A.a-A.b),abs(A.a-A.c))<min(abs(B.a-B.b),abs(B.a-B.c));
}
bool cmpb(ren A,ren B)
{
	return min(abs(A.b-A.a),abs(A.b-A.c))<min(abs(B.b-B.a),abs(B.b-B.c));
}
bool cmpc(ren A,ren B)
{
	return min(abs(A.c-A.b),abs(A.c-A.a))<min(abs(B.c-B.b),abs(B.c-B.a));
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	for(cin>>T;T;T--)
	{
		an=sa=sb=sc=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>nn[i].a>>nn[i].b>>nn[i].c;
			switch(maxx(i))
			{
				case 1:
					sa++;
					an+=nn[i].a;
					nn[i].d=1;
					break;
				case 2:
					sb++;
					an+=nn[i].b;
					nn[i].d=2;
					break;
				case 3:
					sc++;
					an+=nn[i].c;
					nn[i].d=3;
					break;
			}
		}
		if(sa<=n/2&&sb<=n/2&&sc<=n/2)
		{
			cout<<an<<"\n";
			continue;
		}
		if(sa>n/2)
		{
			sort(nn+1,nn+n+1,cmpa);
			for(int i=1;i<=n;i++)
			{
				if(nn[i].d==1)
				{
					if(abs(nn[i].a-nn[i].b)<abs(nn[i].a-nn[i].c))
					{
						nn[i].d=2;
						an-=nn[i].a,an+=nn[i].b;
						sa--,sb++;
					}
					else
					{
						nn[i].d=3;
						an-=nn[i].a,an+=nn[i].c;
						sa--,sc++;
					}
					if(sa<=n/2&&sb<=n/2&&sc<=n/2)
					{
						cout<<an<<"\n";
						break;
					}
				}
			}
		}
		else
		{
			if(sb>n/2)
			{
				sort(nn+1,nn+n+1,cmpb);
				for(int i=1;i<=n;i++)
				{
					if(nn[i].d==2)
					{
						if(abs(nn[i].a-nn[i].b)<abs(nn[i].b-nn[i].c))
						{
							nn[i].d=1;
							an-=nn[i].b,an+=nn[i].a;
							sb--,sa++;
						}
						else
						{
							nn[i].d=3;
							an-=nn[i].b,an+=nn[i].c;
							sb--,sc++;
						}
						if(sa<=n/2&&sb<=n/2&&sc<=n/2)
						{
							cout<<an<<"\n";
							break;
						}
					}
				}
			}
			else
			{
				sort(nn+1,nn+n+1,cmpc);
				for(int i=1;i<=n;i++)
				{
					if(nn[i].d==3)
					{
						if(abs(nn[i].c-nn[i].a)<abs(nn[i].b-nn[i].c))
						{
							nn[i].d=1;
							an-=nn[i].c,an+=nn[i].a;
							sc--,sa++;
						}
						else
						{
							nn[i].d=2;
							an-=nn[i].c,an+=nn[i].b;
							sc--,sb++;
						}
						if(sa<=n/2&&sb<=n/2&&sc<=n/2)
						{
							cout<<an<<"\n";
							break;
						}
					}
				}
			}
		}
	}
	return 0;
 } 
