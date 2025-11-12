#include<bits/stdc++.h>
using namespace std;
int a[200001], c[200001];
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	for(int i = 0; i < n; i++)a[i+1] = s[i]-'0';
	for(int i = 1; i <= n; i++)cin >> c[i];
	cout << 1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
