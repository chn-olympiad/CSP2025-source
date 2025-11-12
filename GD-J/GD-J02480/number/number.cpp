#include <iostream>
#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;
const int N = 1e6 + 5;
int a[N], pos;
string s;

bool cmp(int a, int b){
	return a > b;
}

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	cin >> s;
	for(int i = 0; i < s.size(); ++i)
		if('0' <= s[i] && s[i] <= '9') a[++pos] = (int)(s[i] - '0'); 
	sort(a + 1, a + 1 + pos, cmp);
	for(int i = 1; i <= pos; ++i) cout << a[i];
	cout << "\n";
	return 0;
} 
