#include<bits/stdc++.h>
using namespace std;
int n, m, a[15], kl, shang, yu;
bool cmp(int a, int b){
	return a > b;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n*m; i ++){
		cin >> a[i];
	}
	int x = a[1];
	sort(a+1, a+n*m+1, cmp);
	for(int i = 1; i <= n*m; i ++){
		if(a[i] == x){
			kl = i;
			break;
		}
	}
	shang = int(ceil(kl * 1.0 / n));
	yu = kl % n;
	if(yu == 0) yu = n;
	if(shang % 2){
		for(int i = 1; i <= n; i ++){
			if(i == yu){
				cout << shang << " " << i << "\n";
				return 0;
			}
		}
	}else{
		for(int i = n; i >= 1; i --){
			if(n - i + 1 == yu){
				cout << shang << " " << i << "\n";
				return 0;
			}
		}
	}
	return 0;
}