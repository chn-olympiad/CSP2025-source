#include <bits/stdc++.h>
using namespace std;
int num, sum;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int x;
	for (int i=1;i<=m*n;i++)
	{
		cin >>x;
		if (i==1)
		{
			num=x;
		}
		if (x>num)
		{
			sum++;
		}
	}
	int a=sum/n;
	int b=sum%n;
	if (a%2==1)
	{
	    cout << a+1 << " " << n-b;
    }
	else
	{
		cout << a+1 << " " << b+1;
	}
	return 0;
}