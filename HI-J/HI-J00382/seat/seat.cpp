#include<bits/stdc++.h>
using namespace std;
int x,y,n;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>x>>y>>n;
	int sum=0,num=0;
	for(int i=1;i<x*y;i++)
	{
		cin>>num;
		if(num>n)
		{
			sum++;
		}
	}
	
	if((sum/y)%2==1)
	{
		cout<<sum/y+1<<' '<<y-(sum%x);
	}
	else
	{
		cout<<sum/y+1<<' '<<sum%x+1;
	}
	return 0;
}

