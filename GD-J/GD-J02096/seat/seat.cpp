#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],x=1,h,l;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a[1];
	for(int i=2;i<=n*m;i++)
	{
		cin>>a[i];
		if(a[i]>a[1])
		{
			x++;
		}
	}
	l=(x-1)/n+1;
	x=(x-1)%(2*n)+1;
	if(x>n)
	{
		h=2*n-x+1;
	}
	else
	{
		h=x;
	}
	cout<<l<<" "<<h<<endl;
	return 0;
}
