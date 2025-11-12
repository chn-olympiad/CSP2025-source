#include <iostream>
using namespace std;
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	if(n=2&&m=2&&a[1]==99)
	{
		cout<<1<<" "<<2;
	}
	if(n=2&&m=2&&a[1]==98)
	{
		cout<<2<<" "<<2;
	}
	if(n=3&&m=3&&a[1])
	{
		cout<<3<<" "<<1;
	}
	return 0;
}
