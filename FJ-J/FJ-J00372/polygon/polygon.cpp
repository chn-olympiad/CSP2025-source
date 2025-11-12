#include <bits/stdc++.h>
using namespace std;
int a[5005], n, ans=0;
bool b[5005];

bool cmp(int a, int b){
	return a < b;
}

void func(int k){
	if (k == n-1){
		int m=0, mxn=-1, tl=0;
		for (int i = 0; i < n; i++){
			if (b[i] == 1){
				m ++;
				mxn = max(a[i], mxn);
				tl += a[i];
			}
		}
		if (m >= 3) {
			if (tl > 2 * mxn){
				ans++;
			}
		}
	}
	else{
		func(k+1);
		b[k] = 1;
		func(k+1);
	}
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a+n, cmp);
	func(0);
	printf("%d", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
