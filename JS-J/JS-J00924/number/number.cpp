#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int cnt[10];


int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	for (size_t i=0;i<=s.length();++i){
		if (s[i] >= '0' && s[i] <='9') cnt[s[i]-'0']++;
	}
	for (int i=9;i>=0;--i){
		while (cnt[i]--) cout << i;
	}
	return 0;
}
