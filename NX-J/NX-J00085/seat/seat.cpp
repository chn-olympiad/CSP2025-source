#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int x,y,a,m,n=0;
	double b;
	cin>>a>>b;
	cin>>m;
	for(int i=1;i<=a*b-1;i++)
	{
		cin>>x;
		if(x>m)
		{
			n++;
		}
	}
	n++;
	x=n/a;
	if(x%a!=0)
		x++;
	y=n%a;
	if(x%2==0)
	{
		y+=((b+1)/2-y)*2;
	}
	cout<<x<<" "<<y;																																																																																																	
	return 0;
}
