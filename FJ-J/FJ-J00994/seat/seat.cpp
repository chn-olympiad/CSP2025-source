#include<bits/stdc++.h>
using namespace std;
bool flag=false;
int n,m,x=0,y=1,sum;
struct node{
	int ax,id;
} a[110];
bool cmp(node a,node b)
{
	return a.ax>b.ax;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;++i)
	{
		cin>>a[i].ax;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for (int i=1;i<=n*m;++i)
	{
		if(a[i].id==1)
		{
			sum=i;
			break;
		}
	}
	for (int i=1;i<=n*m;++i)
	{
		if((x==n&&flag==false)||(x==1&&flag==true))
		{
			++y;
			if(flag==true) flag=false;
			else flag=true;
		}
		else if(flag==false) ++x;
		else --x;
		if(i==sum) break;
	}
	cout<<y<<' '<<x<<endl;
	return 0;
}