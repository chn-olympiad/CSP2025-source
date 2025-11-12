#include <bits/stdc++.h>
using namespace std; 

int n, m, a[110], b, k; 

bool compare(int x, int y)
{
	return x > y; 
}

int main()
{
	freopen("seat.in", "r", stdin); freopen("seat.out", "w", stdout); 
	cin >> n >> m; 
	for (int i = 1; i <= n*m; i++)
	{
		cin >> a[i]; 
	}
	b = a[1]; 
	sort(a+1, a+1+n*m, compare); 
	for (int i = 1; i <= n*m; i++)
	{
		if (b == a[i]) 
		{
			k = i; //kÎªÅÅÃû 
			break; 
		}
	}
	cout << ((k%m == 0) ? k/m : k/m+1) << ' ' << ((k%m == 0) ? (((k/m)%2 == 0) ? 1 : m) : (((k/m+1)%2 == 1) ? k%m : m-(k%m)+1)); 
	return 0; 
} 
