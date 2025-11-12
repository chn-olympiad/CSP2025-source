#include <bits/stdc++.h>
using namespace std;
const int N = 210;
int n, m, a[N];
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n*m; i++)
		scanf("%d", &a[i]);
	int i = 1;
	for(int j = 2; j <= n*m; j++)
		if(a[j] > a[1])
			i++;
	int ee = i%n;
	int rr = i/n;
	if(ee == 0)
		ee = n;
	else
		rr++;
	if((rr&1) == 0)
		ee = n-ee+1;
	printf("%d %d", rr, ee);
	return 0;
}
