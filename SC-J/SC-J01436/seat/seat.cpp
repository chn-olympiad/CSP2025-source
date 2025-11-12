#include <bits/stdc++.h>
using namespace std;

int n, m;
int score[10*10];
int people[101], s;
int ans, x, y;

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i=0; i<n*m; i++)
	{
		scanf("%d", &score[i]);
		people[score[i]]++;
	}
	s = score[0];
	for (int i=100; i>=0; i--)
		if (i>s)
			ans+=people[i];
	else
	{
		ans++;
		break;
	}
	x = ceil(1.0*ans/n);
	y = ans-(x-1)*n;
	if (x%2==0)
		y = n-y+1;
	printf("%d %d", x, y);
	return 0;
}