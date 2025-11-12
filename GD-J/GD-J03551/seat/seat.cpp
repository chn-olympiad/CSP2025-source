#include <iostream>
#include <algorithm>
using namespace std;
int n,m,a[101],id=1,x,y;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(i!=1&&a[i]>a[1]) id++;
	}
	//cout<<id<<endl;
	if(id%n==0)
	{
		x=id/n;
		if(x&1) y=n;
		else y=1;
	}
	else
	{
		x=id/n+1;
		id%=n;
		if(x&1) y=id;
		else y=n-id+1;
	}
	cout<<x<<" "<<y<<endl;
	return 0;
}
//[0,100];
//开始写成if(x&2)了wssb警钟敲烂 
