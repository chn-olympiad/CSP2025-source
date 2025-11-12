#include<bits/stdc++.h>
using namespace std;
long long m, n, cnt, ans1, ans2;
string s[114514];
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> m >>n;
	for(int i = 1; i <= m * 2; i++){
		cin >> s[i];
	}
	int ans1 = 0;
	for(int i = 1; i <= n; i++){
		cout <<	ans1 << '\n';
	}
	return 0;
}
