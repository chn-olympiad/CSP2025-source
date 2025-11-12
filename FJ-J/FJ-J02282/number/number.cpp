#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000001], cnt = 1;
bool cmp(int x, int y){
	return x > y;
}
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int l = s.size();
	for(int i = 0; i < l; i ++){
		if(s[i] >= '0' && s[i] <= '9'){
			a[cnt ++] = s[i] - 48;
		}
	}
	sort(a + 1, a + cnt, cmp);
	for(int i = 1; i < cnt; i ++){
		cout << a[i];
	}
	return 0;
}
