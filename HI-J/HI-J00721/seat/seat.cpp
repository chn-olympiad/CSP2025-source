#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	int n, m, k, l, n_, m_;
	cin >> n >> m;
	int ch[n * m + 1];
	for(int i = 1; i <= n * m; i++) cin >> ch[i];
	k = ch[1];
	sort(ch + 1, ch + n * m + 1);
	for(int i = 1; i <= n * m; i++){
		if(ch[i] == k){
			l = n * m - i + 1;
			break;
		}
	}
	if(l % (n * 2) < n && l % (n * 2) > 0){
		m_ = l / n + 1;
		n_ = l % (n * 2);
	}
	else if(l % (n * 2) > n && l % (n * 2) < n * 2){
		m_ = l / n + 1;
		n_ = n - l % n + 1;
	}
	else if(l % (n * 2) == n){
		m_ = l / n;
		n_ = n;
	}
	else if(l % (n * 2) == 0){
		m_ = l / n;
		n_ = 1;
	}
	cout << m_ << ' ' << n_;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
