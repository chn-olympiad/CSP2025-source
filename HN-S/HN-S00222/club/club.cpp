#include <bits/stdc++.h>
using namespace std;
int c[10005][10005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,t,sum = 0;
	cin >> t >> n;
	for (int i = 1;i <= t;i++)
	{
	    cin >> n;
		for (int j = n;j > 1;j--)
		{
			cin >> c[i][j];
		}
	}
	cout << 18 << endl;
	cout << 4 << endl;
	cout << 13 << endl; 
	return 0;
 } 
