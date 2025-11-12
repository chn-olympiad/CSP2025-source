#include<bits/stdc++.h>
using namespace std;
int t;
int n;
struct club{
	int a,b,c;
}d[100005];
int ans=0;
int cnt=0;
int cmp(club x,club y)
{
	return x.a>y.a;
}
int cmd(club x,club y)
{
	return x.b>y.b;
}
int cmf(club x,club y)
{
	return x.c>y.c;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	queue<int> q;
	q.push(0);
	while(t--)
	{
		cnt=0;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>d[i].a>>d[i].b>>d[i].c;
		}
		sort(d,d+n,cmp);
		for(int i=1;i<=n/2;i++)
		{
			if(d[i].a!=d[i-1].a)
			{
				cnt+=d[i-1].a;
				break;
			}
			if(d[i].a==d[i-1].a)
			{
				cnt+=d[i-1].a;
			}
		}
		sort(d,d+n,cmd);
		for(int i=1;i<=n/2;i++)
		{
			if(d[i].b!=d[i-1].b)
			{
				cnt+=d[i-1].b;
				break;
			}
			if(d[i].b==d[i-1].b)
			{
				cnt+=d[i-1].b;
			}
		}
		sort(d,d+n,cmf);
		for(int i=1;i<=n/2;i++)
		{
			if(d[i].c!=d[i-1].c)
			{
				cnt+=d[i-1].c;
				break;
			}
			if(d[i].c==d[i-1].c)
			{
				cnt+=d[i-1].c;
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
