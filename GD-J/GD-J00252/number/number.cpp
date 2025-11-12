#include <iostream>
#include <algorithm>
using namespace std;
int a[1000005], idx = 0;

bool cmp(int a, int b){
	return a > b;
}

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++){
		if ('0' <= s[i] && s[i] <= '9'){
			idx++;
			a[idx] = s[i] - '0';
		}
	}
	sort(a + 1, a + idx + 1, cmp);
	for (int i = 1; i <= idx; i++){
		cout << a[i];
	}
	return 0;
}
