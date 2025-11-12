#include <bits/stdc++.h>
using namespace std;
string a;
int b[1000005];
int m = 0;
bool cmp(int a, int b)
{
	return a > b;
}
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> a;
	int l = a.length();
	for (int i = 0; i < l; i++)
	{
		if ('0' <= a[i] && a[i] <= '9')
		{
			b[m] = a[i] - '0';
			m++;
		}
	}
	sort(b, b + m, cmp);
	for (int i = 0; i < m; i++)
	{
		cout << b[i];
	}
	
	return 0;
}