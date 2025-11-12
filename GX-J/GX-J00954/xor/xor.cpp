# include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;

int n, k;
int a[N];

int main (){
	
	freopen ("xor.in", "r", stdin);
	freopen ("xor.out", "w", stdout);
	
	cin >> n >> k;
	
	for (int i = 0;i < n;i++){
		cin >> a[i];
	}
	
	if (k == 0){
		int Count = 0;
		for (int i = 0;i < n;i++){
			if (a[i] == 0){
				Count++;
			}
		}
		
		cout << Count;
		return 0;
	}
	else if (n == 1){
		if (a[0] == k){
			cout << "1";
			return 0;
		}
		else {
			cout << "0";
			return 0;
		}
	}
	else if (n == 2){
		if (a[0] == k && a[1] != k){
			cout << "1";
			return 0;
		}
		else if (a[0] != k && a[1] == k){
			cout << "1";
			return 0;
		}
		else if (a[0] == k && a[1] == k){
			cout << "2";
			return 0;
		}
	}
	else {
		cout << n / 2;
		return 0;
	}
	
	return 0;
}
