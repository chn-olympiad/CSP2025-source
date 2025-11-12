#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int n , m , t , a[105] = {};
bool cmp(int b , int c)
{
	return b > c;
}
int main()
{
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	cin >> n >> m;
	int kj = n * m;
	for(int i = 0 ; i <= kj - 1 ; i ++)
	{
		cin >> a[i];
		if(i == 0)
		{
			t = a[i];
		}
	}
	sort(a , a + kj , cmp);
	/*for(int i = 0 ; i <= kj - 1 ; i ++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;*/
	int ws;
	for(int i = 0 ; i <= kj - 1 ; i ++)
	{
		if(t == a[i])
		{
			ws = i + 1;
			break;
		}
	}
	//cout << ws << endl;
	int nn = 2 * n;
	int z = ws / nn;
	int x = ws % nn;
	if(x <= n)
		cout << 2 * z + 1 << ' ' << x;
	else if(x > n)
		cout << 2 * z + 2 << ' ' << (nn - x + 1);
	return 0;
}
