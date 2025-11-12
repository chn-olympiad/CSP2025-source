#include <bits/stdc++.h>
using namespace std;
int a[1000010];
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	int n = 0;
	for(int i = 0;i < s.size();i++){
		if(s[i] >= '0' && s[i] <= '9'){
			a[++n] = s[i] - '0';
		}
	}
	sort(a+1, a+n+1, greater<int>());
	for(int i = 1;i <= n;i++){
		cout << a[i];
	}
	cout << "\n";
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
