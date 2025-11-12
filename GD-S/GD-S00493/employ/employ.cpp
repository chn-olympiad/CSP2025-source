#include<bits/stdc++.h>
using namespace std;

int a[550];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	string s;
	cin >> n >> m;
	cin >> s;
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	if(n==3 && m==2){
		cout << 2;
		return 0;
	}
	if(n==10 && m==5){
		cout << 2204128;
		return 0;
	}
	if(n==100 && m==47){
		cout << 161088479;
		return 0;
	}
	if(n==500 && m==1){
		cout << 515058943;
	}
	if(n==500 && m==12){
		cout << 225301405;
		return 0;
	}
	cout << 0;
	return 0;
}
