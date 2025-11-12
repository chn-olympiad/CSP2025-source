#include <bits/stdc++.h>
using namespace std;
int lie, r, n, m, a[105], s, h, num;
bool cmp(int x, int y){
	return x > y;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d", &n, &m);
	s = n * m;
	for(int i = 0; i < s; i++){
		scanf("%d", &a[i]);
	}
	h = a[0];
	sort(a, a + s, cmp);
	for(int i = 0; i < s; i++){
		if(a[i] == h){
			num = i;
			break;
		}
	}
	for(int i = 1; i <= n; i++){
		if(i * m > num){
			lie = i;
			break;
		}
	}
	if(lie % 2 == 1)r = (num % m) + 1;
	else r = lie * m - num;
	printf("%d %d", lie, r);
	return 0;
}

