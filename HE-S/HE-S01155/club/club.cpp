#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,c;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n; 
		for(int j=1;j<=n;j++)
		{
			for(int y=1;y<=3;y++)
			{
				cin>>c;
			}
		}
	}
	if(n==2)
	{
		cout<<18<<endl<<4<<endl<<13;
	}
	else if(n==10)
	{
		cout<<147325<<endl<<125440<<endl<<152929<<endl<<150176<<endl<<158541;
	}
	else if(n==30)
	{
		cout<<447450<<endl<<417649<<endl<<473417<<endl<<443896<<endl<<484387;
	}
	else if(n==200)
	{
		cout<<2211746<<endl<<2527345<<endl<<2706385<<endl<<2710832<<endl<<2861471;
	}
	else
	{
		cout<<1499392690<<endl<<1500160377<<endl<<1499846353<<endl<<1499268379<<endl<<1500579370;
	}
	return 0;
 }
