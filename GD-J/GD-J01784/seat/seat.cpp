#include<iostream>
using namespace std;
int id;
int n,m;
int base;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m>>base;
	
	for(int i=1;i<n*m;i++)
	{
		int x;
		cin>>x;
		
		if(x>base) id++;
	}
	
	int x = 1;
	int y = 1;
	bool flag = true;
	while(id--)
	{
		if(flag)
		{
			x++;
			if(x==n+1)
			{
				y++;
				x = n;
				flag = false;
			}
		}
		else
		{
			x--;
			if(x==0)
			{
				y++;
				x = 1;
				flag = true;
			}
		}
	}
	
	cout<<y<<' '<<x;
	return 0;
}
