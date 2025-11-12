#include <bits/stdc++.h>
using namespace std;
const int N = 500;
int a[N];
bool cmp(int a,int b){
	return a > b;
}
int solve(){
	int n,m;
	cin >> n >> m;
	for(int i = 1 ; i <= n * m ; i++ ) cin >> a[i];
	int r = a[1];
	sort(a + 1 , a + (n * m) + 1);
	int idx = lower_bound(a + 1 , a + (n * m) , r) - a;
	idx = (n * m) - idx + 1;
	if (idx % n == 0){
		if((idx / n) % 2 == 1) cout << idx / n << ' ' << n;
		else cout << idx / n << ' ' << 1;
		return 0;
	}
	int lie = idx / n + 1;
	int b = idx % n;
	if (lie % 2 == 1) cout << lie << ' ' << b;
	else cout << lie << ' ' << n - b + 1;
	return 0;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	solve();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
