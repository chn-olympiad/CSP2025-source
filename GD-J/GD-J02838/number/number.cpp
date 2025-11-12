#include <bits/stdc++.h>
using namespace std;
string s;
int n, a, b, c, d, e, f, g, h, j, k;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	n = s.size();
	for(int i = 0;i < n;i++){
		if(s[i] == '0') a++;
		else if(s[i] == '1') b++;
		else if(s[i] == '2') c++;
		else if(s[i] == '3') d++;
		else if(s[i] == '4') e++;
		else if(s[i] == '5') f++;
		else if(s[i] == '6') g++;
		else if(s[i] == '7') h++;
		else if(s[i] == '8') j++;
		else if(s[i] == '9') k++;
	}
	if(k != 0){
		for(int i = 1;i <= k;i++){
			cout << 9;
		}
	}
	if(j != 0){
		for(int i = 1;i <= j;i++){
			cout << 8;
		}
	}
	if(h != 0){
		for(int i = 1;i <= h;i++){
			cout << 7;
		}
	}
	if(g != 0){
		for(int i = 1;i <= g;i++){
			cout << 6;
		}
	}
	if(f != 0){
		for(int i = 1;i <= f;i++){
			cout << 5;
		}
	}
	if(e != 0){
		for(int i = 1;i <= e;i++){
			cout << 4;
		}
	}
	if(d != 0){
		for(int i = 1;i <= d;i++){
			cout << 3;
		}
	}
	if(c != 0){
		for(int i = 1;i <= c;i++){
			cout << 2;
		}
	}
	if(b != 0){
		for(int i = 1;i <= b;i++){
			cout << 1;
		}
	}
	if(a != 0){
		for(int i = 1;i <= a;i++){
			cout << 0;
		}
	}
	return 0;
}
