#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
string s;
int n, a[N], tot;
bool cmp(int a, int b){
	return a > b;
} 
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> s;
	n = s.length();
	tot = 1;
	for (int i = 0; i < n; ++i){
		if ('0' <= s[i] && s[i] <= '9'){
			a[tot] = s[i]-'0';
			tot+=1;
		}
	}
	sort(a+1, a+tot, cmp);
	for (int i = 1; i <= tot-1; i++){
		cout << a[i];
	}
	cout << "\n";
	return 0;
} 
