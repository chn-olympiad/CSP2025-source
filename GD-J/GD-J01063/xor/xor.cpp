#include <bits/stdc++.h>
using namespace std;

const unsigned int Maxn = 5e5 + 19;
string L[Maxn];
bool b[Maxn];
string sf(int n){
	string s;
	while (n != 0){
		s = s + char(n % 2 + '0');
		n /= 2;
	}
	return s;
}
string xf(string s1, string s2){
	string s;
	if(s1.size() < s2.size()){
		int l = s1.size();
		for (int i = 0; i < l; i++){
			s = s + char((s1[i] - '0' + s2[i] - '0') % 2 + 0);
		}
		l += s2.size();
		for (int i = s1.size(); i < l; i++){
			s = s + s2[i];
		}
		return s;
	}
	else{
		int l = s2.size();
		for (int i = 0; i < l; i++){
			s = s + char((s1[i] - '0' + s2[i] - '0') % 2 + 0);
		}
		l += s1.size();
		for (int i = s2.size(); i < l; i++){
			s = s + s1[i];
		}
		return s;
	}
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, x, tot = 0;
	bool y = 0;
	unsigned int sum = 0;
	cin >> n >> k;
	if (k == 0){
		for (int i = 0; i < n; i++){
			cin >> x;
			if (x == 0){
				sum++;
				y = false;
			}
			else{
				if (y == false) y = true;
				else{
					sum++;
					y = false;
				}
			}
		}
		cout << sum << endl;
		return 0;
	}
	else if (k == 1){
		for (int i = 0; i < n; i++){
			cin >> x;
			if (x == 1) sum++; 
		}
		cout << sum << endl;
		return 0;
	}
	else{
		string sk = sf(k), sa;
		for (int i = 0; i < n; i++){
			if (n - tot < i) break;
			cin >> x;
			if (i == 0) L[i] = sf(x);
			else L[i] = xf(L[i - 1], sf(x));
		}
		for (int i = 1; i < n; i++){
			for (int j = tot; j < n; j++){
				if (xf(L[j], L[j + i]) == sk){
					tot = j + i + 1;
					j = tot;
					sum++;
				}
			}
		}
		cout << sum << endl;
	}
	return 0;
}
