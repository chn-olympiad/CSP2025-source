#include<bits/stdc++.h>
using namespace std;
struct sss
{
	int a,b,c;
}q[10000008];
bool cmp(sss e,sss f)
{
	return e.c<f.c;
}
int af[10008];
long long sum;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,flag=0;
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)
	{
		af[i]=i;
	}
	for(int i=0;i<m;i++)
	{
		cin>>q[i].a>>q[i].b>>q[i].c;
	}
	sort(q,q+m,cmp);
	for(int i=0;i<m;i++)
	{
		if(af[q[i].a]!=-1&&af[q[i].b]!=-1)
		{
			af[q[i].a]=-1,af[q[i].b]=-1,sum=sum+q[i].c;
		}
		if(af[q[i].a]!=-1||af[q[i].b]!=-1)
		{
			if(flag==0) sum=sum+q[i].c,flag=1;
		}
	}
	cout<<sum;
	return 0;
}
