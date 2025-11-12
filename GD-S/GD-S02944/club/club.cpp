#include<bits/stdc++.h>
using namespace std;

const int Max = 1e5 + 7;
int t, n, m, maxx1 = 0, maxx2 = 0;
int a1[Max], a2[Max], a3[Max];
int c2[Max], c3[Max], c[Max];
long long sum = 0;

bool cmp(int a, int b){
	return a > b;
}


void f(long long ans, int s1, int s2, int s3, int i){
	if (s1 > m || s2 > m || s3 > m) return;
	if (i > n) {
		sum = max(sum, ans);
		return;
	}
	f(ans + a1[i], s1 + 1, s2, s3, i + 1);
	f(ans + a2[i], s1, s2 + 1, s3, i + 1);
	f(ans + a3[i], s1, s2, s3 + 1, i + 1);
	
}

void fB(){
	for (int i = 1; i <= n; i++) {
		sum += a1[i];
		c2[i] = a1[i] - a2[i];
	}
	sort(c2 + 1, c2 + 1 + n);
	for (int i = 1; i <= m; i++) sum -= c2[i];
}

void fA(){
	sort(a1 + 1, a1 + n + 1, cmp);
	for (int i = 1; i <= m; i++) sum += a1[i];
}

void fno(){
	cout << -1;
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--){
		cin >> n;
		m = n / 2;
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &a1[i], &a2[i], &a3[i]);
			maxx1 = max(maxx1, a2[i]);
			maxx2 = max(maxx2, a3[i]);
		}
		if (n <= 10) f(0, 0, 0, 0, 1);
		else if (maxx1 == 0 && maxx2 == 0) fA();
		else if(maxx2 == 0) fB();
		else fno();
		printf("%lld\n", sum);
		sum = 0;
	}
	return 0;
}
