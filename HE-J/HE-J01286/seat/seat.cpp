#include <iostream> 
using namespace std;
int fen,x,y,cnt,f,x1,y1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>x>>y>>fen;
	for(int i=1;i<x*y;i++)
	{
		cin>>f;
		if(f>fen)
		{
			cnt++;
			
		}
	}
	
	y1=cnt/x+1;
	x1=cnt%x+1;
	cout<<y1<<' ';
	if(y1%2==1)
	{
		cout<<x1;
	}
	else
	{
		cout<<x+1-x1;
	}

	return 0;
}
