#include<bits/stdc++.h>
using namespace std;
long long tp1=0;
long long tp2=0;
struct M
{
	long long b1,b2,b3,id;	
}p[1000000];
struct N
{
	long long b1,b2,b3,id;
	long long maxx;
}p2[1000000];
bool cmp(N x,N y)
{
	return x.maxx>y.maxx;	
}
bool cmp2(M x,M y)
{
	return x.b1>y.b1;	
}
bool cmp3(M x,M y)
{
	return x.b2>y.b2;	
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int a;
	cin>>a;
	int x;	
	for(long long i=0;i<a;i++)
	{
		int n1=0,n2=0,n3=0;
		cin>>x;
		int ans=x/2;
		long long sum=0;
		for(long long j=1;j<=x;j++)
		{
			cin>>p[j].b1>>p[j].b2>>p[j].b3;
			tp1+=p[j].b2;
			tp2+=p[j].b3;
			p[j].id=j;		
			p2[j].b1=(p[j].b1-p[j].b2)+(p[j].b1-p[j].b3);
			p2[j].b2=(p[j].b2-p[j].b1)+(p[j].b2-p[j].b3);
			p2[j].b3=(p[j].b3-p[j].b1)+(p[j].b3-p[j].b2);
			p2[j].id=j;	
			p2[j].maxx=max(p2[j].b3,max(p2[j].b1,p2[j].b2));	
		}
		if(tp1+tp2==0)
		{
			sort(p+1,p+1+x,cmp2);
			for(int j=1;j<=ans;j++)
			{
				sum+=p[j].b1;
			}
			cout<<sum<<endl;
		}
		else
		{
			sort(p2+1,p2+x+1,cmp);
			for(int j=1;j<=x;j++)		
			{
				if(max(max(p[p2[j].id].b1,p[p2[j].id].b2),p[p2[j].id].b3)==p[p2[j].id].b1)
				{
					if(n1<ans)
					{
						sum+=p[p2[j].id].b1;
						n1++;
					}
					else if(max(p[p2[j].id].b2,p[p2[j].id].b3)==p[p2[j].id].b2&&n2<ans)
					{
						sum+=p[p2[j].id].b2;
						n2++;
					}
					else
					{
						sum+=p[p2[j].id].b3;
						n3++;
					}						
				}
				else if(max(max(p[p2[j].id].b1,p[p2[j].id].b2),p[p2[j].id].b3)==p[p2[j].id].b2)
				{
					if(n2<ans)
					{
						sum+=p[p2[j].id].b2;
						n2++;
					}
					else if(max(p[p2[j].id].b1,p[p2[j].id].b3)==p[p2[j].id].b1&&n1<ans)
					{
						sum+=p[p2[j].id].b1;
						n1++;
					}
					else
					{
						sum+=p[p2[j].id].b3;
						n3++;
					}
				}
				else if(max(max(p[p2[j].id].b1,p[p2[j].id].b2),p[p2[j].id].b3)==p[p2[j].id].b3)
				{
					if(n3<ans)
					{
						sum+=p[p2[j].id].b3;
						n3++;
					}
					else if(max(p[p2[j].id].b2,p[p2[j].id].b1)==p[p2[j].id].b1&&n1<ans)
					{
						sum+=p[p2[j].id].b1;
						n1++;
					}
					else
					{
						sum+=p[p2[j].id].b2;
						n2++;
					}
				}			
			}
			cout<<sum<<endl;
		}		
	}
	return 0;

}

