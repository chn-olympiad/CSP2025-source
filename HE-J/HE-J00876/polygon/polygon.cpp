#include<bits/stdc++.h>
using namespace std;

int n, a[5050];


int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n;
	for(int i=1; i<=n; i++)   cin >> a[i];
	sort(a, a+n+1);
	
	bool l = true;
	for(int i=1; i<=n; i++){
		if(a[i] != 1){
			l = false;
			break;
		}
	}
	
	if(n <= 2){
		cout << 0;
		return 0;
	}
	if(n == 3){
		if(a[3] < a[1]+a[2]){
			cout << 1;
			return 0;
		}else{
			cout << 0;
			return 0;
		}
	}
	
	int ans = 0;
	
	if(l == true){
		int f = log2(n);
		for(int i=1; i<=f; i++){
			ans += n - (pow(2, i) - 1);
		}
	}
	
	cout << ans;
	
	
	return 0;
}
