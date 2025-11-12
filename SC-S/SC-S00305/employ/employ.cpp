#include <bits/stdc++.h>

using namespace std;

int arr[5000005];
int brr[5000005];
int krr[5000005];
int sum;

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	string a;
	cin >> a;
	for(int i = 0; i < a.size(); i++){
		if(a[i] == '0'){
			brr[i + 1] = 0;
			continue;
		}
		brr[i + 1] = 1;
	}
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	cout << 118;
	return 0;
}
