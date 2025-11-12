#include <bits/stdc++.h>
using namespace std;

struct p {
	int a;
	int b;
};

int main() {
	
	//cout << "!!!!!!!";
	int n, k, s[500001], tr[500001][500001];
	
	cin >> n >> k;
	for (int i=0; i<n; i++) {
		cin >> s[i];
	}
//	for (int i=0; i<n; i++) {
//		cout << s[i];
//	}
	
	for (int i=0; i<n; i++) {
		tr[i][i]=s[i];
		for (int j=i+1; j<n; j++) {
			tr[i][j]=tr[i][j-1]^s[j];
		}
	}
	cout << tr[0][0]; 
	
//	for (int i=0; i<n; i++) {
//		for (int j=i; j<n; j++) {
//			cout  << i <<"!!! ";
//		}
//		cout << endl;
//	}
	
	
	return 0;
}
