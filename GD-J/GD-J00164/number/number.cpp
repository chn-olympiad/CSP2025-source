#include <bits/stdc++.h>
using namespace std;
#define int long long
string s;
char a[1000001];
int l = 0;
bool cmp(char a, char b){
	return (int)a > (int)b;
}
signed main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	//scanf("%s", &s);
	for (int i = 0;i < s.size();i++){
		if (s[i] >= '0' && s[i] <= '9'){
			l++;
			a[l] = s[i];
		}
	}
	sort(a + 1, a + 1 + l, cmp);
	for (int i = 1;i <= l;i++){
		cout << a[i];
	}
	return 0;
} 
