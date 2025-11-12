#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

string s;
int cnt[N] , jsq;

bool cmp (int x , int y) {
	return x > y;
}

int main() {
	
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);
	
	cin >> s;
	
	for(int i = 0; i <= s.size(); i++) {
		if(s[i] >= '0' && s[i] <= '9') {
			cnt[i] = s[i] - '0';
			jsq ++;
		}
	}
	
	sort(cnt , cnt + s.size() , cmp);
	
	for(int i = 0; i < jsq; i++) cout << cnt[i];
	
	return 0;
} 
