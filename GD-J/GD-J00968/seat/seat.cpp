#include <bits/stdc++.h>
using namespace std;

const int N = 15;

int n,m;
int num=1,a,b,c,r;

void gc()
{
	cin >> n >> m;
	cin >> a;
	for (int i = 2;i <= n*m;i++)
	{
		cin >> b;
		if (b>a)num++;
	}
	c = (num-1)/n+1;
	if (c%2==1)r = num-(c-1)*n;
	else r = n-num+(c-1)*n+1;
	cout << c << " " << r;
	return;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	gc();
	return 0;
} 
