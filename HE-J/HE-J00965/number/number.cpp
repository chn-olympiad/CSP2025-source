#include <bits/stdc++.h>
using namespace std;

int main(){
	string s[1000001];
	cin >> s;
	//s = "290es1q0";
	int a[1000001];
	int e[1000001];
	int j = 0;
	for (int i = 0;i < s.length();i++){
		if (s[i] == 0 || s[i] == 1 || s[i] == 2 || s[i] == 3 || s[i] == 4 || s[i] == 5 || s[i] == 6 || s[i] == 7 || s[i] == 8 || s[i] == 9){
			a[j] = s[i];
			j++;
		}
	}
	for (int k = 0;k < a.length();k++){
		for (int l = 0;l < a.length();l++){
			int c = 0;
			int d = 0;
			if (a[l] > c){
				c = a[l];
				d = l;
			}
		}
		e[k] = c;
		a[d] = 0;
	}
	cout << e;
	return 0;
}
