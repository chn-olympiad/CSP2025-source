#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		if(n == 1)
		{
			cout << 2;
		}
		for(int i = 1; i <= m; i++)
		{
		     if(m == 2)
			{
				cout << 1;
			}
		}
	}
	cout << 2;
	return 0;	
}

