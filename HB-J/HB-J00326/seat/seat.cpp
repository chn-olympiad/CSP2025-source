#include <bits/stdc++.h>
using namespace std;
int n,m;
int student;
int prenum=0;	// from the first to XiaoR's position
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>student;
	for(int i=2;i<=(n*m);i++)
	{
		int x;
		cin>>x;
		if(x>student)
		{
			prenum++;
		}
	}
	int row,cal;
	bool forward=0;	// down or up? 1/0
	row=cal=1;	// the first position
	for(int i=1;i<=prenum;i++)
	{
		if(forward==0)	// it means down
		{
			row++;
			if(row>n)
			{
				row--;
				cal++;
				forward=1;	// it turns around
			}
		}
		else //it means up
		{
			row--;
			if(row<1)
			{
				row++;
				cal++;
				forward=0;	// turns around again
			}
		}
	}
	cout<<cal<<' '<<row;
	return 0;
}
