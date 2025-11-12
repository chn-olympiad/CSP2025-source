#include<bits/stdc++.h>
using namespace std;
int a[1000010];
bool cmp(int c1, int c2){
	return (c1 > c2);
}
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int num = 0, n = s.size();
	for(int i = 0; i < n; i++){
		if(s[i] >= '0' && s[i] <= '9') a[++num] = s[i] - '0';
	}
	sort(a + 1, a + num + 1);
	for(int i = num; i >= 1; i--){
		cout << a[i];
	}
	return 0;
}
