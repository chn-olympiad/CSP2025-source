#include <bits/stdc++.h>
using namespace std;

struct score
{
	int id,a;
}s[101];

bool cmp(score x,score y)
{
	return x.a>y.a;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,sum;
	cin>>n>>m;
	sum=n*m;
	for(int i=1;i<=sum;i++)
	{
		cin>>s[i].a;
		s[i].id=i;
	}
	sort(s+1,s+sum,cmp);
	for(int i=1;i<=sum;i++)
	{
		if(s[i].id==1)
		{
			int r,c;
			r=(n+i-1)/n;
			if(r%2==1)
			{
				c=i%n;
				if(c==0)
				{
					c=n;
				}
			}
			else
			{
				c=n+1-i%n;
				if(c==n+1)
				{
					c=1;
				}
			}
			cout<<r<<' '<<c;
			break;
		}
	}
	return 0;
}