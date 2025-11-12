#include<bits/stdc++.h>
using namespace std;
int a[1000001];
string s;
bool cmp(int x, int y){
	return x > y;
}
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out","w", stdout);
	cin >> s;
	int j = 0;
	for(int i = 0;i < s.size();i++){
		if('0' <= s[i] && s[i] <= '9'){
			a[++j] = s[i] - '0';
		}
	}
	sort(a + 1,a + j + 1,cmp);
	for(int i = 1;i <= j;i++){
		cout << a[i];
	}
	return 0;
}