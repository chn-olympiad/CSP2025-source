#include<bits/stdc++.h>
using namespace std;
bool cmp(int x, int y){
	return x > y;
}
long long a[200009] = { 0 };
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);	
	string s;
	cin >> s;
	long long cnt = 0;
	for (int i = 0; i < s.length(); i++) 
		if (s[i] >= '0' && s[i] <= '9')
			a[cnt++] = (int) s[i] - '0';
	sort (a, a + cnt, cmp);
	for (int i = 0; i < cnt; i++) cout << a[i];
	return 0;
}
