#include<bits/stdc++.h>
using namespace std;
struct node
{
	int id,zhi;
};
node a[110];
bool cmp(node a,node b)
{
	return a.zhi>b.zhi;
}
int n,m;
int xr;
int ceee(int a,int b)
{
	if(a%b==0)return a/b;
	return a/b+1;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		a[i].id=i; 
		scanf("%d",&a[i].zhi);
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i].id==1)
		{
			xr=i;
			break; 
		}
	}
	int xrn=ceee(xr,n);
	int xrm;
	if(xr%n==0)
	{
		xrm=n;
	}
	else
	{
		xrm=(xr%n);
	}
	
	if(xrn%2==0)
	{
		xrm=(n+1-xrm);
	}
	cout<<xrn<<" "<<xrm;
	return 0;
}
