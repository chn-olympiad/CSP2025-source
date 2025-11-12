#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000005];
bool cmp(int x, int y){
	return x > y;
}
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	s = " " + s;
	int n = 0;
	for(int i = 1; i <= s.size(); i++){
		if(s[i] >= '0' && s[i] <= '9'){
			a[++n] = s[i] - '0';
		}
	}
	sort(a + 1, a + n + 1, cmp);
	for(int i = 1; i <= n; i++){
		cout << a[i];
	}
	return 0;
} 
