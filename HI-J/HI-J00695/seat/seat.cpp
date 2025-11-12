#include <bits/stdc++.h>
using namespace std;
int arr1[101];
int arr2[11][11];
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout); 
	int n, m;
	cin >> n >> m; 
	int a = n * m;
	for(int i = 1;i <= a;i++){
		cin >> arr1[i];
	}
	int xrs = arr1[1];
	sort(arr1 + 1, arr1 + n + 1);
	for(int i = 1;i <= a;i++){
		if(arr1[i] == xrs){
			cout << (i / (n * m) + 1) * m <<" "<< i / (n * m) * m;
			return 0;
		}
	}
	return 0;
} 
