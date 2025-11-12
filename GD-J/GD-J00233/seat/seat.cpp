#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN=1e6+10;
int n,m;
int a[MAXN];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int x=n*m;
	for(int i=1;i<=x;i++)
	cin>>a[i];
	int y=a[1],pos;
	sort(a+1,a+x+1,cmp);
	for(int i=1;i<=x;i++)
	{
		if(y==a[i])
		{
			pos=i;
			break;
		}
	}
	int c=pos/n+1,r=pos%n;
	if(r==0)
	{
		c--;
		if(c%2==0)
		cout<<c<<" "<<1;
		else
		cout<<c<<" "<<n;
		return 0;
	}
	if(c%2==0)
	cout<<c<<" "<<n-r+1;
	else
	cout<<c<<" "<<r;
	return 0;
}
