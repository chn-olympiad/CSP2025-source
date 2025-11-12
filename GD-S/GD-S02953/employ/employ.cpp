#include<bits/stdc++.h>
using namespace std;
const int N = 505;
int n, m, a[N], c[N], p[N], cnt;
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		char ch; cin >> ch;
		a[i] = ch-'0';
	}
	for(int i = 1; i <= n; i++) cin >> c[i];
	for(int i = 1; i <= n; i++) p[i] = i;
	do{
		int now = 0;
		for(int i = 1; i <= n; i++){
			if(now >= c[p[i]] || a[i] == 0){
				++now;
			}
		}
		if(n-now >= m) cnt++;
	} while(next_permutation(p+1, p+1+n));
	cout << cnt << '\n';
	return 0;
}
