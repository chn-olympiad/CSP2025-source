#include <bits/stdc++.h>
using namespace std;

int a[1000010], k = 0;
string s;

bool cmp(int x, int y){
	return x > y;
}

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		if(isdigit(s[i])){
			a[++k] = s[i] - '0';
		}
	}
	sort(a + 1, a + k + 1, cmp);
	for(int i = 1; i <= k; i++){
		cout << a[i];
	}
	cout << '\n';
	return 0;
}
