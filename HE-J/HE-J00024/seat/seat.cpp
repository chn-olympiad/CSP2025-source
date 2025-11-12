#include <bits/stdc++.h>
using namespace std;
int cmp(int x,int y)
{
	if (x > y)
		return x > y;
	else
		return y > x;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,n1,m1;
	int a[105];
	cin >> n >> m;
	int s = n*m;
	for (int i = 1;i <= s;i++)
	{
		cin >> a[i];
	}
	int p = a[1],p1;
	sort(a + 1,a + s + 1,cmp);
	for (int j = 1;j <= s;j++)
	{
		if (a[j] == p)
			p1 == j;
	}
	int p2 = p1 / n;
	if (p2 % 2 == 0){
		n1 = n-p1 % n; 
	}
	if (p2 % 2 == 1)
	{
		n1 = p1 % n;
	}
	m1 = p2;
	cout << m1 << " " << n1; 
 } 
