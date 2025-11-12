#include<bits/stdc++.h>
using namespace std;
const int N = 5010;
int a[N];
bool used[N];
int cnt = 0;
int m = -1;
int tot = 0;
int refreshmax(int n){
	int m2 = -1;
	for (int i = 1; i <= n; ++i){
		if (used[i]) continue;
		m2 = max(m2,a[i]);
	}
	return m2;
}

void check(int m1, int tot1, int depth, int n){
	if (m1 == -1) m1 = refreshmax(n);
	if (m1 * 2 < tot1) cnt++;
	if (depth == 3) return ;
	else{
		for (int i = 1; i <= n; ++i){
			if (used[i]) continue;
			used[i] = 1;
			if (i == m1) check(-1,tot1-a[i],depth-1,n);
			else check(m1,tot1-a[i],depth-1,n);
			used[i] = 0;
		}
	}
}
int main(){
	//task polygon ..........
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	a[0] = 0;
	for (int i = 1; i <= n; ++i){
		cin >> a[i];
		m = max(m,a[i]);
		tot += a[i];
	}
	check(m,tot,n,n);
	cout << cnt % 998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
