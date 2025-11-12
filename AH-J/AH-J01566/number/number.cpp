#include<bits/stdc++.h>
using namespace std;
string st;
long long n;
map <char, long long> a;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> st;
	n = st.length();
	for (int i = 0; i <= n; i++)
		if(st[i] >= '0' && st[i] <= '9')
			a[st[i] - '0']++;
	for (int i = 9; i >= 0; i--)
		while (a[i]--)
			cout << i;
	return 0;
}
