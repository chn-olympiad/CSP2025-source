#include<bits/stdc++.h>
using namespace std;

int n, m, a[400];
int a1;

bool cmp(int x, int y) 
{
	return x > y;
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >> n >> m;	
	for(int i = 0; i < n * m; i++) 
		scanf("%d", &a[i]);
	a1 = a[0];
	sort(a, a + n * m, cmp);
	
	for(int i = 0; i < n * m; i++) 
		if(a[i] == a1)
		{
			cout << i / n + 1 << ' ';
			if(i / n % 2)
				cout << n - (i - i / n * n);
			else
				cout << i - i / n * n + 1;
		}
	return 0;
}
