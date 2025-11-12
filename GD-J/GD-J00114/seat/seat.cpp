#include <bits/stdc++.h>
using namespace std;

struct nodefx{
	int value, id;
}a[int(105)];

int n, m;
int rx = 1, cx = 1;
int cnt = 0;

bool cmp(nodefx a, nodefx b){
	if (a.value != b.value ) return a.value > b.value;
	else return a.id < b.id;
}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	scanf("%d %d", &n, &m);
	for (int i=1;i<=n*m;i++) {
		scanf("%d", &a[i].value );
		a[i].id = i;
	}
	sort(a + 1, a + n*m + 1, cmp);
	while (rx <= n && cx <= m){
		if (a[++cnt].id == 1){
			printf("%d %d", cx, rx);
			return 0;
		}
		if (cx%2){
			if (rx + 1 <= n) rx ++ ;
			else cx ++ ;
		}else {
			if (rx - 1 >= 1) rx -- ;
			else cx ++ ;
		}
	}
	printf("-1");
	fclose(stdin);
	fclose(stdout);
	return 0;
}

