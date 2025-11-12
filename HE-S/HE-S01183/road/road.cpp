#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,NN=2e6+5;
struct Dl{
	int u,v,q;
}d[NN];
bool b[N];
bool cmp(Dl a,Dl b)
{
	if(a.u==b.u)
	{
		return a.q>b.q;
		if(a.v==b.v)
		{
			if(a.q<b.q)
			{
				b.q=-1;
			}
			else
			{
				a.q=-1;
			}
		}
	}
	return a.u>b.u;
}
int main()
{
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>d[i].u>>d[i].v>>d[i].q;
		d[m+i].v=d[i].u;
		d[m+i].u=d[i].v;
		d[m+i].q=d[i].q;
	}
	sort(d+1,d+n+1,cmp);
	long long sum=0;
	for(int i=1;i<=m;i++)
	{
		if(!bool[d[i].u])
		{
			if(d[i].q!=-1)
			{
				sum+=d[i].q;
				bool[d[i].u]=1;
				bool[d[i].v]=1;
			}
		}
	}
	cout<<sum;
	return 0;
}
