#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int a[N], n, m;
bool cmp(int a, int b){
	return a > b;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	int l = n * m;
	for(int i = 1; i <= l; i++){
		scanf("%d", &a[i]);
	}
	int x = a[1], xi;
	sort(a + 1, a + l + 1, cmp);
	for(int i = 1; i <= l; i++){
		if(a[i] == x){
			xi = i;
			break;
		}
	}
	int i = xi / n;
	if(xi % n != 0) i++;
	int j = (xi - 1) % n + 1;
	if(i % 2 == 0) j = n - (j - 1);
	printf("%d %d", i, j);
	return 0;
}