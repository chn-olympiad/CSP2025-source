#include<bits/stdc++.h>

using namespace std;

int x[1000010];

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	char a[1000010];
	cin >> a;
	//cout << a << endl;
	int rec = 0;
	int tmp = strlen(a);
	//cout << strlen(a) << endl;
	for (int i = 0;i < tmp;i++)
	{
		if (48 <= a[i] && a[i] <= 57)
		{
			x[rec] = a[i] - 48;
			//cout << x[rec] << endl;
			rec++;
		}
	}
	sort(x, x + rec);
	for (int i = 1;i <= rec;i++)
	{
		cout << x[rec - i];
	}
	return 0; 
} 
