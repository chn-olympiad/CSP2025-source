#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int a, b;
	cin >> a >> b;
	int s[11][11], d[11][11], q[122], t=0;
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			cin >> s[i][j];
			q[t]=s[i][j];
			t++;
		}	
	}
	int w=s[1][1];
	sort(q, q+t);
	for(int i=1;i<=a;i=i+2)
	{
		for(int j=1;j<=b;j++)
		{
			d[i][j]=q[t];
			t--;
			if(q[t]==w)
			{
				cout << i << " " << j;
				break;
			}
		}	
		for(int y=b;y>=1;y--)
		{
			int r=i;
			d[r+1][y]=q[t];
			t--;
			if(q[t]==w)
			{
				cout << i+1 << " " << y;
				break;
			}
		}	
	}
	return 0;
}
