#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m,k,sum=0;
struct s
{
	int u;
	int v;
	int w;
}a[N];
struct c
{
	int s;
	int sc[N];
}p[N];
void f()
{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<k;j++)
		{
			if(a[i].w>=p[j].s+p[j].sc[a[i].u]+p[j].sc[a[i].v])
			{
				sum+=p[j].s+p[j].sc[a[i].u]+p[j].sc[a[i].v];
			}
			else
			{
				sum+=a[i].w;
			}
			
		}
	}
}
int main()
{
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
	{
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=0;i<k;i++)
	{
		cin>>p[i].s;
		for(int j=0;j<n;j++)
		{
			cin>>p[i].sc[j];
		}
	}
	f();
	cout<<sum<<endl;
	return 0;
}
