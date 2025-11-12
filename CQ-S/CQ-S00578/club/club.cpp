#include<bits/stdc++.h>
using namespace std;

int t,n,ans;
int ls[100005][3],c[3];

struct p
{
	int id,x,d;
}m[100005];

bool cmp(p x,p y)
{
	int a=ls[x.id][x.x],b=ls[x.id][x.d],u=ls[y.id][y.x],v=ls[y.id][y.d];
	if(a-b!=u-v) return a-b>u-v;
	return b>v;
}

void f(int &i)
{
	int mi=min(ls[i][0],min(ls[i][1],ls[i][2]));
	if(ls[i][0]==mi)
	{
		if(ls[i][1]<ls[i][2])
		{
			m[i].x=2;
			m[i].d=1;
		}
		else
		{
			m[i].x=1;
			m[i].d=2;
		}
	}
	else if(ls[i][1]==mi)
	{
		if(ls[i][0]<ls[i][2])
		{
			m[i].x=2;
			m[i].d=0;
		}
		else
		{
			m[i].x=0;
			m[i].d=2;
		}
	}
	else
	{
		if(ls[i][0]<ls[i][1])
		{
			m[i].x=1;
			m[i].d=0;
		}
		else
		{
			m[i].x=0;
			m[i].d=1;
		}
	}
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		memset(c,0,sizeof(c));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&ls[i][0],&ls[i][1],&ls[i][2]);
			m[i].id=i;
			f(i);
		}
		sort(m+1,m+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			if(c[m[i].x]<n/2)
			{
				ans+=ls[m[i].id][m[i].x];
				c[m[i].x]++;
			}
			else
			{
				ans+=ls[m[i].id][m[i].d];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
