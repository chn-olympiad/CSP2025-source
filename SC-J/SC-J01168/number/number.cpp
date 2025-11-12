#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int b[105];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for(int i = 0;i < s.size();i ++){
		if(isdigit(s[i])){
			b[s[i] - '0'] ++;
		}
	}
	for(int i = 9;i >= 0;i --){
		while(b[i]){
			cout << i;
			b[i] --;
		}
	}
	return 0;
}