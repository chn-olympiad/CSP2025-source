#include <bits/stdc++.h>
using namespace std;
int main(){
	//一定要改!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string a;
	cin >> a;
	int b = a.size();
	int A[58];
	char B[a.size() + 1];
	if (b == 1){
		cout << a;
	}
	for (int i = 0; i <= 9; i++){
		A[i+48] = i;
	} 
	for (int i = 0; i < a.size; i++){
		B[i] = char(a[i]);
	}
	if (b == 2){
		int c = A[int(char(a[0]))];
		int d = A[int(char(a[1]))];
		if (c > d){
			cout << ;
		}
		else{
			cout << a;
		}
	}
	return 0; 
} 
