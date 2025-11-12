#include<bits/stdc++.h>
using namespace std;
int n, m, i, t, a[110];
bool cmp(int a, int b){return a > b;}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for(i = 0;i < n * m;i++)scanf("%d", a + i);
	i = 0, t = a[0], sort(a, a + n * m, cmp);
	while(a[i] != t)i++;
	i++, t = ceil(i * 1.0 / n);
	printf("%d %d", t, t % 2 ? i - (i - 1) / n * n : n + i / n * n - i + 1);
	return 0;
}
