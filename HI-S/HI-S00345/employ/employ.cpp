#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	int n, m, sum = 0, ans = 1;
	cin >> n >> m;
	int c[n];
	string s;
	cin >> s;
	for(int i = 0; i < n; i++) cin >> c[i];
	for(int i = 0; i < n; i++)
		if(s[i] == '1') sum ++;
	if(sum < m){
		cout << 0;
		return 0;
	}
	for(int i = 1; i <= n; i++) ans = (i * ans) % 998244353;
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
