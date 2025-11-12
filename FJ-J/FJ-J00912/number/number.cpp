#include<bits/stdc++.h>
using namespace std;
int pos[10];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for(auto c: s)
		if(isdigit(c))
			pos[c-'0']++;
	for(int i = 9; i >= 0; i --)
		for(int j = 0; j < pos[i]; j++)
			cout << i;
}
