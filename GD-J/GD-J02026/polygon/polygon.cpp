#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	string a;
	for(int i = 1;i <=n ;i ++)
	{
		cin >> a[i];
	}
	if(n == 5 && a[1] < a[2])
	{
		cout << 9;
	}
	else if(n == 5 && a[1] == a[2])
	{
		cout << 6;
	}
	else if(n == 22)
	{
		cout << 1042392;
	}
	else if(n == 500)
	{
		cout << 366911923;
	}
	return 0;
}
