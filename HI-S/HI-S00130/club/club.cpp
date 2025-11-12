#include<bits/stdc++.h>
using namespace std;
int n,m,k,l;
bool f=1,g=1;
struct jg{
	int p1,p2,p3;
}a[12345]; 
bool cmp(jg s,jg b)
{

	return s.p1> b.p1;
	
}
int main()
{ 
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&m);
	while(m--)
	{
		bool f=1,g=1;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i].p1,&a[i].p2,&a[i].p3);
			if(a[i].p1!=0)
			{
				f=0;
			}
			if(a[i].p2!=0)
			{
				g=0;
			}
		}
		sort(a+1,a+n+1,cmp);
		if(f==0&&g==0)
		{
			int y=0;
			for(int i=1;i<=n/2;i++)
			{
				y+=a[i].p2; 
			}
			printf("%d\n",y);
		}
		else
		{
			int y=0;
			for(int i=1;i<=n/2;i++)
			{
				y+=a[i].p1;
			}
			for(int i=n/2;i<=n;i++)
			{
				y+=a[i].p2;
			}
			printf("%d\n",&y);
		}
		
	}
		
	return 0;
 } 
