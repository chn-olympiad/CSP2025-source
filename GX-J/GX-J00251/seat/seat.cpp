#include <bits/stdc++.h>

using namespace std;

int main()
{
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m,xiaoming=1;//行数n 与 列数m
	cin >> n >> m;
	int xm;
	cin >> xm;
	for (int i=0;i<n*m-1;i++)
	{
		int temp;
		cin >> temp;
		if (temp>xm) xiaoming+=1;
	}
	
	if (xiaoming%2==0)
	{
		if (xiaoming % n == 0) cout << xiaoming/n << ' ' << 1;
		else cout << xiaoming/n+1 << ' ' << n-xiaoming%n+1;
	}
	else
	{
		if (xiaoming % n == 0) cout << xiaoming/n << ' ' << n;
		else cout << xiaoming/n+1 << ' ' << xiaoming%n;
	}
	return 0;
}
