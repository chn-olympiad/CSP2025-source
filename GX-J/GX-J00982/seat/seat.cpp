#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m];
	int b=1;
	for(int i=1;i<=n*m;i++)
	  cin>>a[i];
	for(int j=2;j<=n*m;j++)
	{
		if(a[b]<a[j])b=b+1;
		else b=b;
	}
	int r=0,c=0;
	for(int z=n;z<=n*m;z=z+n)
	{
	  if(b>z)c=c+1;
	  else {r=b%(c*n);c=c;}

    }
    c=c+1;
    if(c%2>0)cout<<c<<""<<r;
    else 
    {
		if(c%2==0)
		  r=n-r+1;
		cout<<c<<" "<<r;
	}
	return 0;
}

