#include<bits/stdc++.h>
using namespace std;
int a;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int b,xc=0;
    cin>>b;
    for(int i=1;i<n*m;i++)
	{
		cin>>a;
		if(a>b) xc++;
	}
	int x=1,y=1;
	bool fx=0;
	while(xc>0)
	{
		xc--;
		if(fx==0) x++;
		else x--;
		if(x>n)
		{
			y++;
			fx=1;
			x--;
		}
		if(x<1)
		{
			y++;
			fx=0;
			x++;
	}
}
	cout<<y<<" "<<x;
	return 0;
}
