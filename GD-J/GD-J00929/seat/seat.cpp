#include<bits/stdc++.h>
#define LL long long
using namespace std;

const LL maxn = 15;
LL n, m, pos, r, c;
struct node
{
	LL num;
	LL id;
}a[maxn * maxn];
bool cmp(node a, node b)
{
	return a.num > b.num;
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++)
		cin >> a[i].num, a[i].id = i;
	sort(a + 1, a + 1 + n * m, cmp);
	for(int i = 1; i <= n * m; i++)
		if(a[i].id == 1)
		{
			pos = i;
			break;
		}
	c = pos / n;
	if(pos % n != 0) c++;
	if(c % 2 == 1)
		r = m - (c * n - pos);
	else
		r = c * n - pos + 1;
	cout << c << ' ' << r;
	return 0;
}
