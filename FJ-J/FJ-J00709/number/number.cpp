#include <bits/stdc++.h>
using namespace std;
string s;
int cnt;
int a[1000005];

int main(){
	freopen("number.out","w",stdout);
	cin >> s;
	freopen("number.in","r",stdin);
	for(int i=0; i<s.size();i++){
		if(s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9'){
			a[++cnt] = char(s[i] - '0');
		}
	}
	sort(a+1,a+cnt+1,greater<int>());
	for(int i=1; i<=cnt; i++){
		cout << a[i];
	}
	return 0;
}
