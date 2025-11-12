#include<bits/stdc++.h>
using namespace std;
bool som(int d,int b)
{
	return d>b;
}
int a[105];
int op[15][15];
int main()
{
	int n,m;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	int t=n*m;
	for(int i=1;i<=t;i++)
	{
		cin>>a[i];
	}
	int b=a[1];
	sort(a+1,a+t+1,som);
	
	int x=1,y=1;
	bool dy=false;
	for(int i=1;i<=t;i++)
	{
		int o=i/n;
		if(i%n==0)
		{
			o--;
		}
		if(i%n==1&&i!=1)
		{
			x++;
			if(o%2==0)
			{
				dy=false;
			}
			else
			{
				dy=true;
			}
		}
		if(a[i]==b)
		{
			int g=i%n;
			if(g==0)
			{
				g=n;
			}
			if(dy==false)
			{
				y=g;
				
			}
			else
			{
				
				y=n-g+1;
			}
			
			cout<<x<<" "<<y;
			break;
		}
	}
	return 0;
}
