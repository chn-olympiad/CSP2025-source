#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[500111];
void solve1(){//A
	cout << n / 2 << "\n";
	exit(0);
}
void solve2(){//B
	int ans = 0;
	if (k == 0){
		for (int i = 1;i <= n;i++){
			if (a[i] == 0){
				ans++;
				continue;
			}
			if (a[i + 1] == 1){
				i++;
				ans++;
			}
		}
	}else{
		for (int i = 1;i <= n;i++){
			if (a[i] == 1){
				ans++;
				continue;
			}
			if (a[i] == 0 && a[i + 1] == 1){
				ans++;
				i++;
				continue;
			}
			if (a[i] == 1 && a[i + 1] == 0){
				ans++;
				i++;
				continue;
			}
		}
	}
	cout << ans << "\n";
	exit(0);
}
void solve3(){
	int ans = 0;
	for (int i = 1;i <= n;i++){
		if (a[i] == 0){
			ans++;
			continue;
		}
		if (a[i] == a[i + 1]){
			ans++;
			i++;
			continue;
		}
	}
	cout << ans << "\n";
	exit(0);
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	bool b = true,f = true;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
		if (a[i] != 1){
			b = false;
		}
		if (a[i] > 1){
			f = false;
		}
	}
	if (b){//A
		solve1();
	}
	if (f){//B
		solve2();
	}
	if (k == 0){
		solve3();
	}
	int l = 1,r = 1,ans = 0,sum = 0,jr = 0;
	while (r <= n + 1){
		sum = sum ^ a[r];
		if (a[r] == k){
			ans++;
			jr = r;
			l = r + 1;
			sum = a[l];
		}
		if (sum == k && jr < l){//满足条件 
//			cout << "a1 = ";
//			for (int i = l;i <= r;i++){
//				cout << a[i] << " ";
//			}cout << "\n";
			ans++;
			jr = r;
			l = r + 1;
			sum = a[l];
		}else{
			int cnt = sum,i;
			bool v = false;
			for (i = jr + 1;i <= r;i++){
				cnt = cnt ^ a[i];
				if (cnt == k){
					v = true;
					break;
				}
			}
			if (v){
//				cout << "sum = " << sum << "\n";
//				cout << "l = " << l << "\n";
//				cout << "r = " << r << "\n";
//				cout << "jr = " << jr << "\n";
//				cout << "i = " << i << "\n";
//				cout << "a2 = ";
//				for (int j = i;j <= r;j++){
//					cout << a[j] << " ";
//				}cout << "\n";
				ans++;
				jr = r;
				l = r + 1;
				sum = a[l];
			}
		}
		r++;
	}
	cout << ans << "\n"; 
	return 0;
}
/*
6 3
1 2 3 4 2 3
*/