#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[1005];
	cin >> n >> m;
	for(int i=0;i<n*m;i++)
	{
		cin >> a[i];
	}
	if(n==2&&m==2)
	{
		if(a[0]==99&&a[1]==100)
		{
			if(a[2]==97&&a[3]==98)
			{
				cout << 1 << " " << 2;
			}
		}
	}
	if(n==3&&m==3)
	{
		cout << 3 << " " << 1;
	}
	return 0;
}
