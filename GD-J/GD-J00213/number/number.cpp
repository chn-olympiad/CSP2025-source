#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
string str;
int a[N];
int cmp(int a, int b){
	return a > b;
}
int main () {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> str;
	int cnt = 0;
	int l = str.size();
	for(int i = 0;i < l;i++){
		if(str[i] >= '0' && str[i] <= '9'){
			a[i] = str[i]-'0';
			cnt++;
		}
	}
	sort(a, a+l, cmp);
	if(a[1] == 0){
		cout << 0;
	}
	else{
		for(int i = 0;i < cnt;i++){
			cout << a[i];
		}
	}
	return 0;
}
