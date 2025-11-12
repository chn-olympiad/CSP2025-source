#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.in","w",stdout);
	int a,m,b[100],p,q,x,y;
	cin>>a>>m;
	cin>>p;
	q=0;
	for(int i=0;i<a*m-1;i++)
	{
		cin>>b[i];
		if(b[i]>p)
		{
			q++;
		}
	}
	x=q/a+1;
	if(x%2==0)
	{
		y=a-q%a;
	}
	else if(x%2==1)
	{
		y=q%a+1;
	}
	cout<<x<<' '<<y;
}

