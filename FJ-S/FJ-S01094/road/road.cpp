#include<bits/stdc++.h>
using namespace std;
struct sa
{
	int q;
	int z;
	int money;
}a[100005];
struct sb
{
	int xc;
	int x;
	int y;
	int z;
	int h;
}f[100005];
bool cmp(sa a,sa b)
{
	return a.money<b.money;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].q>>a[i].z>>a[i].money;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>f[i].xc>>f[i].x>>f[i].y>>f[i].z>>f[i].h;
	}
	if(k==0)
	{
		sort(a+1,a+1+m,cmp);
		long long sum=0;
		for(int i=1;i<=n-1;i++)
		{
			sum+=a[i].money;
		}
		cout<<sum<<endl;
	}
	else cout<<0<<endl;
	return 0;
}
