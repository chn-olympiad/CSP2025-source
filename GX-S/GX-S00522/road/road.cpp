#include<bits/stdc++.h>
using namespace std;
long long int u[1001000],v[1001000],w[1001000];
struct path
{
	vector<int>a;
	int cum=1;
}val[1001000];
int main()
{
	long long int n,m,k,MIN=9999999,r,l,o,cum=0;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(u[j]==i||v[j]==i)
			{
				if(w[j]<MIN)
				{
					MIN=w[j];
					l=u[j];
					r=w[j];
					if(l!=i)
					{
						o=l;
					}
					else
					{
						o=r;
					}
				}
			}
		}
		cum+=MIN;
		MIN=9999999;
		val[i].a.push_back(o);
		for(auto t=val[i].a.begin();t!=val[i].a.end();t++)
		{
			val[i].a.push_back(*t);
		}
	}
	int y=0;
	for(int i=1;i<=n;i++)
	{
		if(val[i].a[i]==i)
		{
			y++;
			continue;
		}
	}
	if(y==n)
	{
		cout<<cum;
	}
	return 0;
}
