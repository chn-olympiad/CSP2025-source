#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node
{
	int a,b,c,id;
}a[N];
int f1[N],t1[5],ss[N][5];
struct line111
{
	int x,y,id1;
}pl[N];
bool cmp1(node sz,node sz1)
{
	return sz.a>sz1.a;
}
bool cmp(line111 pl1,line111 pl2)
{
	return pl1.x<pl2.x;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(f1,0,sizeof(f1));
		memset(t1,0,sizeof(t1));
		for(int i=1;i<=N;i++)
		{
			a[i].a=0;
			a[i].b=0;
			a[i].c=0;
			a[i].id=0;
		}
		for(int i=1;i<=N;i++)
		{
			pl[i].x=100000;
			pl[i].y=0;
			pl[i].id1=0;
		}
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
			a[i].id=i;
		}
		int f=0;
		for(int i=1;i<=n;i++)
			if(a[i].b!=0||a[i].c!=0)
				f=1;
		if(f==0)
		{
			int s=0;
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=n/2;i++)
				s+=a[i].a;
			cout<<s<<endl;
		}//A
		for(int i=1;i<=n;i++)
		{
			if(a[i].a>=a[i].b&&a[i].a>=a[i].c)
			{
				f1[a[i].id]=1;
				t1[1]++;
			}
			else if(a[i].b>=a[i].a&&a[i].b>=a[i].c)
			{
				f1[a[i].id]=2;
				t1[2]++;
			}
			else
			{
				f1[a[i].id]=3;
				t1[3]++;
			}
		}
		
		if(t1[1]>n/2)
		{
			for(int i=1;i<=n;i++)
			{
				if(f1[a[i].id]!=1)
					continue;
				if(t1[1]<=n/2)
					break;
				ss[a[i].id][2]=a[a[i].id].a-a[a[i].id].b;
				ss[a[i].id][3]=a[a[i].id].a-a[a[i].id].c;
				if(ss[a[i].id][2]<ss[a[i].id][3])
				{
					pl[a[i].id].id1=a[i].id;
					pl[a[i].id].x=ss[a[i].id][2];
					pl[a[i].id].y=2;
				}
				else
				{
					pl[a[i].id].id1=a[i].id;
					pl[a[i].id].x=ss[a[i].id][3];
					pl[a[i].id].y=3;
				}
			}
			sort(pl+1,pl+n+1,cmp);
			for(int i=1;i<=t1[1]-(n/2);i++)
				f1[pl[i].id1]=pl[i].y;
		}
		
		
		if(t1[2]>n/2)
		{
			for(int i=1;i<=n;i++)
			{
				if(f1[a[i].id]!=2)
					continue;
				if(t1[2]<=n/2)
					break;
				ss[a[i].id][1]=a[a[i].id].b-a[a[i].id].a;
				ss[a[i].id][3]=a[a[i].id].b-a[a[i].id].c;
				if(ss[a[i].id][1]<ss[a[i].id][3])
				{
					pl[a[i].id].id1=a[i].id;
					pl[a[i].id].x=ss[a[i].id][1];
					pl[a[i].id].y=1;
				}
				else
				{
					pl[a[i].id].id1=a[i].id;
					pl[a[i].id].x=ss[a[i].id][3];
					pl[a[i].id].y=3;
				}
			}
			sort(pl+1,pl+n+1,cmp);
			for(int i=1;i<=t1[2]-(n/2);i++)
				f1[pl[i].id1]=pl[i].y;
		}
		
		
		if(t1[3]>n/2)
		{
			for(int i=1;i<=n;i++)
			{
				if(f1[a[i].id]!=3)
					continue;
				if(t1[3]<=n/2)
					break;
				ss[a[i].id][2]=a[a[i].id].c-a[a[i].id].b;
				ss[a[i].id][1]=a[a[i].id].c-a[a[i].id].a;
				if(ss[a[i].id][2]<ss[a[i].id][1])
				{
					pl[a[i].id].id1=a[i].id;
					pl[a[i].id].x=ss[a[i].id][2];
					pl[a[i].id].y=2;
				}
				else
				{
					pl[a[i].id].id1=a[i].id;
					pl[a[i].id].x=ss[a[i].id][1];
					pl[a[i].id].y=1;
				}
			}
			sort(pl+1,pl+n+1,cmp);
			for(int i=1;i<=t1[3]-(n/2);i++)
				f1[pl[i].id1]=pl[i].y;
		}
		int s=0;
		for(int i=1;i<=n;i++)
		{
			if(f1[a[i].id]==1)
				s+=a[a[i].id].a;
			else if(f1[a[i].id]==2)
				s+=a[a[i].id].b;
			else
				s+=a[a[i].id].c;
		}
		cout<<s<<endl;
	}
	return 0;
}
