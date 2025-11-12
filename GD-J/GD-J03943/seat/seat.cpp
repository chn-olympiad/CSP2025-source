#include <bits/stdc++.h>
using namespace std;
int n,m;
int value[105]; 
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n*m;i++)
	{
		cin>>value[i];
	}
	int r = value[1];
	sort(value+1,value+n*m+1);
	for(int i = n*m;i>=1;i--)
	{
		if(value[i] == r)
		{
			int l = 1;
			int h = 0;
			int bl = (n*m-i+1);
			bool up = 0;
			while(1)
			{
				if(bl < n)
				{
					if(up == 1)
					{
						h = n-bl+1;
					}
					else
					{
						h = bl;
					}
					break;
				}
				l++;
				up = !up;
				bl -= n;
			}
			cout<<l<<" "<<h;
			return 0;
		} 
	} 
	return 0;
}
/*
3 3
94 95 96 97 98 99 100 93 92
*/
