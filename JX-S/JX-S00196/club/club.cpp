#include<bits/stdc++.h>
using namespace std;
struct asd
{
	int a,s,d;
};
bool dp(asd z,asd c)
{
	if(z.a==c.a&&z.s==c.s) return z.d>c.d;
	else if(z.a==c.a) return z.s>c.s;
	return z.a>c.a;
}
asd q[100002];
int main()
{
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
int n,v[4];
cin>>n;
for(int i=1;i<=n;i++)
{
	int m,p=0;
	v[1]=0;
	v[2]=0;
	v[3]=0;
	cin>>m;
	for(int j=1;j<=m;j++)
	{
		cin>>q[j].a>>q[j].s>>q[j].d;
	}
	sort(q+1,q+n+1,dp);
	for(int j=1;j<=m;j++)
	{
		if(q[j].a>=q[j].s&&q[j].a>=q[j].d&&v[1]<int(m/2))
		{
			p+=q[j].a;
			v[1]++;
		}
		else if(q[j].s>=q[j].a&&q[j].s>=q[j].d&&v[2]<int(m/2))
		{
			p+=q[j].s;
			v[2]++;
		}
		else if(q[j].d>=q[j].a&&q[j].d>=q[j].s&&v[3]<int(m/2))
		{
			p+=q[j].d;
			v[3]++;
		}
		else
		{
			if(q[j].a>=q[j].s||q[j].a>=q[j].d)
			{
				p+=q[j].a;
			    v[1]++;
			}
			else if(q[j].s>=q[j].a&&q[j].s>=q[j].d&&v[2]<m/2)
			{
				p+=q[j].s;
				v[2]++;
			}
			else
			{
				p+=q[j].d;
				v[3]++;
			}
		}
	}
	cout<<p<<endl;
}

return 0;
}
