#include<bits/stdc++.h>

using namespace std;

int n, m, a[200], b;

bool cmp(int a, int b){
	return a > b;
}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n * m; i++){
		scanf("%d", &a[i]);
	}
	b = a[1];
	sort(a + 1, a + (n * m + 1), cmp);
	int k;
	for(int i = 1; i <= n * m; i++){
		if(a[i] == b) {
			k = i;
			break;
		}
	}
	int h, l;
	l = ceil(k / (n * 1.0));
	k -= (l - 1) * n;
	if(l % 2){
		h = k;
	}else h = n - k + 1;
	cout << l << " " << h;
	return 0;
}
