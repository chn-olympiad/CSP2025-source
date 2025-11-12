#include<iostream>
#include<algorithm>

using namespace std;

int t;

int n;

struct people
{
	int a;
	int b;
	int c;
	int dist;
}p[100005];

people a[100005],b[100005],c[100005];

int an,bn,cn,ans=0;

void init()
{
	ans=0;
	
	for(int i=0;i<=100000;i++)
	{
		an=bn=cn=0;
		
		a[i]=b[i]=c[i]=p[i]=(people){0,0,0,0};
	}
}

bool cmp(people a,people b)
{
	return a.dist<b.dist;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	
	while(t--)
	{
		init();
		
		cin>>n;
		
		for(int i=1;i<=n;i++)
		{
			cin>>p[i].a>>p[i].b>>p[i].c;
			
			if(p[i].a>=p[i].b&&p[i].b>=p[i].c)
			{
				ans+=p[i].a;
				
				an++;
				
				p[i].dist=p[i].a-p[i].b;
				
				a[an]=p[i];
			}
			else if(p[i].a>=p[i].c&&p[i].c>=p[i].b)
			{
				ans+=p[i].a;
				
				an++;
				
				p[i].dist=p[i].a-p[i].c;
				
				a[an]=p[i];
			}
			else if(p[i].b>=p[i].a&&p[i].a>=p[i].c)
			{
				ans+=p[i].b;
				
				bn++;
				
				p[i].dist=p[i].b-p[i].a;
				
				b[bn]=p[i];
			}
			else if(p[i].b>=p[i].c&&p[i].c>=p[i].a)
			{
				ans+=p[i].b;
				
				bn++;
				
				p[i].dist=p[i].b-p[i].c;
				
				b[bn]=p[i];
			}
			else if(p[i].c>=p[i].a&&p[i].a>=p[i].b)
			{
				ans+=p[i].c;
				
				cn++;
				
				p[i].dist=p[i].c-p[i].a;
				
				c[cn]=p[i];
			}
			else if(p[i].c>=p[i].b&&p[i].b>=p[i].a)
			{
				ans+=p[i].c;
				
				cn++;
				
				p[i].dist=p[i].c-p[i].b;
				
				c[cn]=p[i];
			}
		}
		
		if(an>n/2)
		{
			sort(a+1,a+an+1,cmp);
			
			for(int i=1;i<=an-n/2;i++)
			{
				ans-=a[i].dist;
			}
		}
		else if(bn>n/2)
		{
			sort(b+1,b+bn+1,cmp);
			
			for(int i=1;i<=bn-n/2;i++)
			{
				ans-=b[i].dist;
			}
		}
		else if(cn>n/2)
		{
			sort(c+1,c+cn+1,cmp);
			
			for(int i=1;i<=cn-n/2;i++)
			{
				ans-=c[i].dist;
			}
		}
		
		cout<<ans<<endl;
	}
}

