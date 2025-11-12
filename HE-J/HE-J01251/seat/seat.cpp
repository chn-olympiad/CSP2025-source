#include<bits/stdc++.h>
using namespace std;
const int N = 15;
int a[225];
int n, m, cnt, c, r;
bool cmp(int na, int nb){
	return na > nb;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cnt++;
			scanf("%d", &a[cnt]);
		}
	}
	int R = a[1];
	sort(a + 1, a + 1 + cnt, cmp);
	for(int i = 1; i <= cnt; i++){
		if(a[i] == R){
			c = i / n + 1;
			r = i % n;
			if(r == 0){
				r = n;
				c--;
			}
			if(c % 2 == 0) r += n - r;
			break;
		}
	}
	printf("%d %d", c, r);
	return 0;
}
