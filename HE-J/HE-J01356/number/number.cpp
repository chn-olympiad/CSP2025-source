#include <bits/stdc++.h> 
using namespace std;
string s;
int a[1000005], poss = 0, posa = 1;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int n = s.size();
	while (poss < n){
		int x = s[poss++] - '0';
		if (x >= 0 && x <= 9){ 
			a[posa++] = x;
		}
	}
	posa--;
	sort(a + 1, a + posa + 1);
	for (int i = posa; i >= 1; i--){
		cout << a[i];
	}
	return 0;
}
