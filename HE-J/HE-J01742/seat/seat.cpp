#include<bits/stdc++.h>
using namespace std;
int main()
{
	preopen("seat.in","r",stdin);
	preopen("seat.out","w",stdout);
	int a[15][15],b[105],n,m,t,ans,s=0;
	cin >>n>>m;
	for (int i=1;i<=n*m;i++)
	{
		cin >>b[i];
		if (i==1)
		{
			t=b[i];
		}
		else
		{
			if (b[i]>t)
			{
				s++;
			}
		}
	}
	for (int j=1;j<=n;j++)
	{
		if (j%2==0)
		{
			for (int i=n;i>=1;i--)
			{
				if (s==0)
				{
					cout <<j<<" "<<i;
					return 0;
					//3 3
//94 95 96 97 98 99 100 93 92

				}
				s--;

			}
		}
		else
		{
			for (int i=1;i<=m;i++)
			{
				if (s==0)
				{
					cout <<j<<" "<<i;
					return 0;
				}
				s--;
			}
		}
		//2 2 99 100 97 98
	}//2 2 99 100 97 98
	cout <<s;
	return 0;
}
