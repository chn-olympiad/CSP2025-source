#include<bits/stdc++.h>
using namespace std;
int t,a[20001],n;
struct member
{
	int ahc;
	int cha;
	int id;
	int a;
	int b;
	int c;		
}m[100001];

bool teler=true;
bool teb=true;
bool cdd(member a,member b)
{
	if(a.ahc>b.ahc)
	{
		return a.ahc<b.ahc;
	}
}
bool cbd(member a,member b)
{
	if(a.cha>b.cha)
	{
		return a.cha<b.cha;
	}
}
bool cmd(member a,member b)
{
	if(a.a<b.a)
	{
		return a.a>b.a;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	member copy[100001];
	member az[100001];
	member bz[100001];
	for(int i=1;i<=t;i++)
	{
		teler=true;
		teb=true;
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			m[j].id=j; 
			cin>>m[j].a>>m[j].b>>m[j].c;
			copy[j].a=m[j].a;
			copy[j].b=m[j].b;
			copy[j].c=m[j].c;
			copy[j].id=m[j].id;
			m[j].ahc=abs(m[j].b-m[j].a);
			m[j].cha=abs(m[j].a-m[j].b);
			copy[j].ahc=m[j].ahc;
			if(m[j].b!=0||m[j].c!=0)
				teler=false;
			if(m[j].c!=0)
				teb=false;
		}
		if(teler)
		{
			teb=false;
			sort(m+1,m+n+1,cmd);
			long long sum=0;
			/*for(int j=1;j<=n;j++)
			{
				cout<<m[j].a<<"  ";
			} */
			for(int j=1;j<=n/2;j++)
			{
				sum+=m[j].a;
			} 
			 cout<<sum<<endl;
		}
		else{
			for(int i=1;i<=t;i++)
			{
				cout<<0;
			}
		}
		/*
		if(teb)
		{
			int a[20001]={0},b[20001]={0};
			int ta=1,tb=1,av=0,bv=0;
			for(int j=1;j<=n;j++)
			{
				if(m[j].a>=m[j].b)
				{
					az[ta].cha=m[j].cha;
					az[ta].id=m[j].id;
					a[ta]=m[j].id;
					ta++;
					av++;
				}
				else
				{
					bz[tb].ahc=m[j].ahc;
					bz[tb].id=m[j].id;
					b[tb]=m[j].id;
					tb++;
					bv++;
				}
			}
			sort(bz+1,bz+tb,cmd);
			if(av>n/2)
			{
				sort(copy+1,copy+n+1,cbd);
				for(;av>n/2;)
				{
					for(int j=1;j<=n;j++)
					{
						if(copy[j].cha<0)
						{
							continue;
						}
						else
						{
							b[tb]=m[copy[j].id].b;
							tb++;
							av--;
							bv++;
							a[copy[j].id]=0;
							copy[j].cha=-1;
							break;
						}
					}
				}
			}
			
			if(bv>n/2)
			{

				int quq=bv-n/2;
				for(int yu=1;yu<=quq;yu++)
				{
					for(int j=1;j<=n;j++)
					{
						if(copy[j].ahc<0)
						{
							continue;
						}
						else
						{
							a[ta]=m[copy[j].id].a;
							ta++;
							bv--;
							av++;
							b[copy[j].id]=0;
							copy[j].ahc=-1;
							break;
						}
					}
					
				}
			}
			
			int sumo=0;
			for(int j=1;j<ta;j++)
			{
				sumo+=m[a[j]].a;
			}
			for(int j=1;j<tb;j++)
			{
				sumo+=m[b[j]].b;
			}
			cout<<sumo<<endl;
		} 
		*/
		
		
	}
	return 0;
}
