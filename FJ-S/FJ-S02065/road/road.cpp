#include<iostream>
#include<cstdio>
using namespace std;
struct road
{
	int a1,b1,c1;
}aa[100];
struct city
{
	int t;
}ax[100];
int main()
{
	/*preopen("road.in","r",stdin);
	preopen("road.out","w",stdout);*/
	int n;
	int m;
	int p;
	int sum=0;
	cin>>n>>m>>p;
	for(int i=0;i<m;i++)
	{
		cin>>aa[i].a1>>aa[i].b1>>aa[i].c1;
	
	}
	for(int i=0;i<p;i++)
	{
		for(int j=0;j<=n;j++)
		{
			cin>>ax[i].t;
		}
	}
	for(int i=0;i<m;i++)
	{
		if(aa[i].a1==aa[i+1].a1)
		{
			sum=aa[i].c1+aa[i+1].c1;
		}
	}
	cout<<sum;
	int r=1000;
	for(int i=0;i<=n;i++)
	{
		if(ax[i].t<r)
		{
			r=ax[i].t;
		}
	}
	sum++;
	sum+=r;
	sum++;
	cout<<sum;
	return 0;
}
