#include <bits/stdc++.h>
#include <cstring>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int y;
	cin>>y;
	if (y=3)
	{
		for (int i=0;i<3;i++)
		{
			int a,b,c;
			cin>>a>>b>>c;
			if(a+b<=c||a+c<=b||b+c<=a) 
			{
				cout<<0;
			}
			else
			{
				cout<<1;
			}
		}
	}
	
	return 0;
} 
