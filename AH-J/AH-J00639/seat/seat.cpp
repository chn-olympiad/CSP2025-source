#include <bits/stdc++.h>
using namespace std;
struct student{
	int cj,y,xi,xj;
}a[100];
bool cmp(const student a,const student b)
{
	return a.cj>=b.cj;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int k=n*m;
	for(int i=1;i<=k;i++)
	{
		cin>>a[i].cj;
		a[i].y=i;
	}
	sort(a+1,a+k+1,cmp);
	int t=0;
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				a[++t].xi=j;
				a[t].xj=i;
			}
		}
		else if(i%2==0)
		{
			for(int j=n;j>=1;j--)
			{
				a[++t].xi=j;
				a[t].xj=i;
			}
		}
	}
	for(int i=1;i<=k;i++)
	{
		if(a[i].y==1)
		{
			cout<<a[i].xj<<" "<<a[i].xi;
			return 0;
		}	
	}
	return 0;
}
