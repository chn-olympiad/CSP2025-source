#include<bits/stdc++.h>

using namespace std;

int a[110], n, m;
bool cmp(int x, int y){
	return x > y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n * m; i++)
		scanf("%d", &a[i]);
	int t = a[1], j;
	sort(a+1, a+n*m+1, cmp);
	for (int i = 1; i <= n*m; i++)
		if (a[i] == t)
			j = i;
	int x, y;
	if (j % n != 0)
		x = j / n + 1;
	else
		x = j / n;
	int r = j % n;
	if (r == 0)
		r = n;
	if (x % 2 == 0)
		y = n - r + 1;	
	else
		y = r;
	printf("%d %d", x, y);
	return 0;
}
