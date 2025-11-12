#include<bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i <= b; i++)

const int N = 105;
int n, m, a[N], b[N];

bool cmp(int x, int y)
{
	return a[x] > a[y];
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	rep(i, 1, n * m) scanf("%d", a + i), b[i] = i;
	sort(b + 1, b + n * m + 1, cmp);
	int res = b[1] - 1;
	int h = 1, l = 1;
	bool flg = 1;
	while(res > 0)
	{
		res--;
		if(flg) h++;
		else h--;
		if(h == n || h == 1) flg ^= 1, l++, res--; 
	}
	if(res < 0) l--;
	printf("%d %d", l, h);
	return 0;
}
