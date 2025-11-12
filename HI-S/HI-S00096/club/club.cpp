#include<bits/stdc++.h>
using namespace std;
const int M=1e5+5;
long long n,t,l[5];
long long ans=0;
struct ab{
	long long a,b,c,d,e,f,g;
}m[M];
int xd(ab a,ab b)
{
	if(a.g!=b.g)
	{
		return a.g>b.g;
	}
	return a.d>b.d;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		l[1]=0;
		l[2]=0;
		l[3]=0;
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>m[i].a>>m[i].b>>m[i].c;
			if(m[i].a>m[i].b&&m[i].a>m[i].c)
			{
				m[i].d=m[i].a;
				m[i].e=1;
				m[i].f=max(m[i].b,m[i].c);
			}
			else if(m[i].b>m[i].a&&m[i].b>m[i].c)
			{
				m[i].d=m[i].b;
				m[i].e=2;
				m[i].f=max(m[i].a,m[i].c);
			}
			else
			{
				m[i].d=m[i].c;
				m[i].e=3;
				m[i].f=max(m[i].b,m[i].a);
			}
			m[i].g=m[i].d-m[i].f;
		}
		sort(m+1,m+n+1,xd);
		for(int i=1;i<=n;i++)
		{
			if(l[m[i].e]+1<=n/2)
			{
				l[m[i].e]++;
				ans+=m[i].d;
			}
			else
			{
				ans+=m[i].f;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
