#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,n;
struct node
{
	int a,b,c;
	int sco1,sco2,sco3;
}s[100005];
int sum,ans;
int vis[5],cc[100005];
bool f=true;
bool cmp(node a,node b)
{
	int m1a=max(a.a,max(a.b,a.c)),m3a=min(a.a,min(a.b,a.c));
	int m1b=max(b.a,max(b.b,b.c)),m3b=min(b.a,min(b.b,b.c));
	int m2a=a.a+a.b+a.c-m1a-m3a;
	int m2b=b.a+b.b+b.c-m1b-m3b;
	if(m1a-m2a<m1b-m2b)return true;
	else if(m1a-m2a==m1b-m2b)
	{
		if(m1a-m3a<m1b-m3b)return true;
		else if(m1a-m3a==m1b-m3b)return m2a-m3a<m2b-m3b;
	}
	return false;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		sum=0;
		memset(vis,0,sizeof vis);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].c);
			if(s[i].b!=0||s[i].c!=0)f=false;
			if(s[i].a>s[i].b&&s[i].a>s[i].c)
			{
				sum+=s[i].a;
				s[i].sco1=1;
				if(s[i].b>s[i].c)s[i].sco2=2,s[i].sco3=3;
				else s[i].sco2=3,s[i].sco3=2;
				vis[1]++;
			}
			else if(s[i].b>s[i].a&&s[i].b>s[i].c)
			{
				sum+=s[i].b;
				s[i].sco1=2;
				if(s[i].a>s[i].c)s[i].sco2=1,s[i].sco3=3;
				else s[i].sco2=3,s[i].sco3=1;
				vis[2]++;
			}
			else if(s[i].c>s[i].b&&s[i].c>s[i].a)
			{
				sum+=s[i].c;
				s[i].sco1=3;
				if(s[i].a>s[i].b)s[i].sco2=1,s[i].sco3=2;
				else s[i].sco2=2,s[i].sco3=1;
				vis[3]++;
			}
		}
		if(f)
		{
			for(int i=1;i<=n;i++)
			{
				cc[i]=s[i].a;
			}
			sort(cc+1,cc+1+n);
			for(int i=n;i>=n/2;i--)
			{
				sum+=cc[i];
			}
			printf("%d",sum);
			return 0;
		}
		sort(s+1,s+1+n,cmp);
		for(int i=1;i<=n;i++)
		{
			if(vis[s[i].sco1]>n/2)
			{
				if(vis[s[i].sco2]+1<=n/2)
				{
					vis[s[i].sco2]++;
					vis[s[i].sco1]--;
					int x,y;
					if(s[i].sco1==1)x=s[i].a;
					else if(s[i].sco1==2)x=s[i].b;
					else x=s[i].c;
					if(s[i].sco2==1)y=s[i].a;
					else if(s[i].sco2==2)y=s[i].b;
					else y=s[i].c;
					sum-=x-y;
				}
				else
				{
					vis[s[i].sco3]++;
					vis[s[i].sco1]--;
					int x,y;
					if(s[i].sco1==1)x=s[i].a;
					else if(s[i].sco1==2)x=s[i].b;
					else x=s[i].c;
					if(s[i].sco3==1)y=s[i].a;
					else if(s[i].sco3==2)y=s[i].b;
					else y=s[i].c;
					sum-=x-y;
				}
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}

