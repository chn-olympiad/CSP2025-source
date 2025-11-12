#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
struct dd
{
	int b1,b2,b3;
} ll[100001],pp[1000];
bool cmp(dd x,dd y)
{
	return x.b1>y.b1;
}
int t,n,aa[100001],bb[100001],cc[100001];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int a=0,b=0,c=0,sam=0;
		for(int i=1;i<=n;i++)
		    scanf("%d%d%d",&ll[i].b1,&ll[i].b2,&ll[i].b3);
		if(n==2)
		{
			int p=0;
			for(int i=1;i<=n;i++)
			{
			    pp[++p].b1=ll[i].b1;
			    pp[p].b2=i;
			    pp[p].b3=1;
			    pp[++p].b1=ll[i].b3;
			    pp[p].b2=i;
			    pp[p].b3=2;
			    pp[++p].b1=ll[i].b2;
			    pp[p].b2=i;
			    pp[p].b3=3;
			}
			sort(pp+1,pp+6+1,cmp);
			for(int i=1;i<=p;i++)
			     for(int j=1;j<=p;j++)
				     if(pp[i].b2!=pp[j].b2 && pp[i].b3!=pp[j].b3)
		                  sam=max(sam,pp[i].b1+pp[j].b1);
		    cout<<sam<<endl;
			continue;
		}
		else
		for(int i=1;i<=n;i++)
		{
		    if(ll[i].b1>=ll[i].b2)
		         if(ll[i].b1>=ll[i].b3)
					 if(a<n/2)//
		                 aa[++a]=i;
		             else
		             {
						 int ans=ll[aa[1]].b1,v=1;
		                 for(int j=2;j<=a;j++)
		                     if(ll[aa[j]].b1<ans)
		                     {
								 ans=ll[aa[j]].b1;
								 v=j;
						     }
						 if(ll[aa[v]].b2>ll[aa[v]].b3)
						         bb[++b]=aa[v];
						 else
						         cc[++c]=aa[v];
						 aa[v]=i;
				      }//
		         else
		             if(c<n/2)//
		                 cc[++c]=i;
		             else
		             {
						 int ans=ll[cc[1]].b3,v=1;
		                 for(int j=2;j<=c;j++)
		                     if(ll[cc[j]].b3<ans)
		                     {
								 ans=ll[cc[j]].b2;
								 v=j;
						     }
						 if(ll[cc[v]].b1>ll[cc[v]].b2)
						         aa[++a]=cc[v];
						 else
						         bb[++b]=cc[v];
						 cc[v]=i;
				      }//
		    else
		        if(ll[i].b2>=ll[i].b3) 
		             if(b<n/2)//
		                 bb[++b]=i;
		             else
		             {
						 int ans=ll[bb[1]].b2,v=1;
		                 for(int j=2;j<=b;j++)
		                     if(ll[bb[j]].b2<ans)
		                     {
								 ans=ll[bb[j]].b2;
								 v=j;
						     }
						 if(ll[bb[v]].b1>ll[bb[v]].b3)
						         aa[++a]=bb[v];
						 else
						         cc[++c]=bb[v];
						 bb[v]=i;
				      }//
			    else 
					 if(c<n/2)//
		                 cc[++c]=i;
		             else
		             {
						 int ans=ll[cc[1]].b3,v=1;
		                 for(int j=2;j<=c;j++)
		                     if(ll[cc[j]].b3<ans)
		                     {
								 ans=ll[cc[j]].b3;
								 v=j;
						     }
						 if(ll[cc[v]].b1>ll[cc[v]].b2)
						         aa[++a]=cc[v];
						 else
						         bb[++b]=cc[v];
						 cc[v]=i;
				      }//
	    }
		for(int i=1;i<=n/2;i++)
		    sam+=ll[aa[i]].b1+ll[bb[i]].b2+ll[cc[i]].b3;
		cout<<sam<<endl;
		memset(aa,0,(a+1)*sizeof(aa[0]));
		memset(bb,0,(b+1)*sizeof(bb[0]));
		memset(cc,0,(c+1)*sizeof(cc[0]));
	}
	return 0;
}
