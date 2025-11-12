#include <bits/stdc++.h>
using namespace std;
struct node
{
	int num , id;
	bool operator<(const node & b)
	const{
		return num > b.num;
	};
}a[1001];
int main()
{
	freopen("seat.in" , "r" , stdin); 
	freopen("seat.out" , "w" , stdout);
	int n , m;
	cin >> n >> m;
	for(int i = 1 ; i <= n * m ; i++)
	{
		cin >> a[i].num;
		a[i].id = i;
	}
	sort(a + 1 , a + n * m + 1);
	int p = -1;
	for(int i = 1; i <= n * m ; i++)
	{
		if(a[i].id == 1)p = i;
	}
	int x = (p - 1) / n + 1 , y;
	if(x % 2 == 1) y = (p - 1) % n + 1;
	else y = n - ((p - 1) % n);
	cout << x << " " << y << endl;
	return 0;
}
