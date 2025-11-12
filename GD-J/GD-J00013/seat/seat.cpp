#include <iostream>
#include <algorithm>
using namespace std;
struct contestant
{
	int g,n;
}c[105];
int n,m;
bool cmp(contestant x,contestant y)
{
	return x.g>y.g;
}
int main()
{
//	freopen("seat.in","w",stdout);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>c[1].g;
	c[1].n=1;
	for(int i=2;i<=n*m;i++)
	{
		cin>>c[i].g;
		c[i].n=i;
	} 
	sort(c+1,c+n*m+1,cmp);
	int a=0;
	for(int i=1;i<=n*m;i++)
	{
		if(c[i].n==1)
		{
			a=i;
			break;
		}
	}
	int co;int ln;
	if(a%m==0)
	{
		co=a/m;
		ln=n;
	} 
	else
	{
	 	co=a/m+1;
	 	ln=a-n*(co-1);
	}
	if(co%2==0)
	{
		ln=n-ln+1;
	}
	cout<<co<<' '<<ln<<'\n';
	
	return 0;
}
