#include<bits/stdc++.h>
using namespace std;
int n,m,x,s=1,h=1,l=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>x;
	for(int i=1;i<n*m;i++)
	{
		int y;
		cin>>y;
		if(y>x)
		{
			h=h+s;
		}
		if(h>n)
		{
			h=n;
			l++;
			s=-1;
		}
		if(h<1)
		{
			h=1;
			l++;
			s=1;
		}
	}
	cout<<l<<" "<<h;
	return 0;
 } 
