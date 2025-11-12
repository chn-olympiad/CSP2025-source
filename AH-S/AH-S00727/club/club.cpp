#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;
int t,n,dp[maxn];
bool f[maxn];

struct qwq
{
	int a,b,c;
}d[maxn];

bool cmp(qwq s,qwq t)
{
	if(s.a==t.a)
	{
		if(s.b==t.b)
			return s.c<t.c;
		return s.b<t.b;
	}
	return s.a<t.a;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		int sum=0,suma=0,sumb=0,sumc=0;
		for(int i=1;i<=100000;i++)
			f[i]=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>d[i].a>>d[i].b>>d[i].c;
		if(n==2)
		{
			sum=max(max(d[1].a+d[2].b,d[1].c+d[2].b),max(d[1].c+d[2].a,max(d[1].b+d[2].a,max(d[1].a+d[2].c,d[1].b+d[2].c))));
			cout<<sum<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++)
			if(d[i].b==0 && d[i].c==0)
				suma++;
		if(suma==n && n!=2)
		{
			sort(d+1,d+n+1,cmp);
			for(int i=n;i>=n/2;i--)
				sum+=d[i].a;
			cout<<sum<<"\n";
		}
		else
		{
			sort(d+1,d+n+1,cmp);
			int j=n/2;
			for(int i=n;i>=1;i--)
			{
				if(suma==n/2)
					break;
				if(d[i].a>max(d[i].b+d[i-j].a,d[i].c+d[i-j].a))
				{
					sum+=d[i].a;
					f[i]=1;
					suma++;
				}
				else
				{
					sum+=max(d[i].b+d[i-j].a,d[i].c+d[i-j].a);
					if(d[i].b+d[i-j].a>d[i].c+d[i-j].a)
						sumb++;
					else
						sumc++;
					f[i-j]=1,f[i]=1;
					j++;
					suma++;
					i++;
				}
			}
			for(int i=n;i>=1;i--)
				if(f[i]==0)
					sum+=max(d[i].b,d[i].c);
			cout<<sum<<"\n";
			}
	}
	return 0;
}
