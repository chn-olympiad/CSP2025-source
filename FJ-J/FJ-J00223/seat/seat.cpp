#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b; 
}
int main()
{
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdin);
		
	int n,m;
	cin >> n >> m;
	//cout << n << m;
	int seat[n*m+1]={0};
	for (int i=1;i<=n*m;i++)
	{
		cin >> seat[i];
	}
	int R=seat[1];
	sort(seat+1,seat+n*m+1,cmp);
	for (int i=1;i<=n*m;i++)
	{
		if(seat[i]==R)
		{
			//cout << i << endl;
			if (i%m==0)
			{
				cout << i/m << " ";
				if (i/m%2==0)
				{
					cout << 1;
					return 0;
				}
				else
				{
					cout << n;
					return 0;
				}
			}
			else
			{
				cout << i/m+1 << " ";
				if ((i/m+1)%2==0)
				{
					cout << n-i%n+1;
					return 0;
				}
				else
				{
					cout << i%n;
					return 0;
				}
			}
		}
	}
	return 0;
}
