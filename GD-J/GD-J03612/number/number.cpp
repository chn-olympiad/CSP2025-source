#include<bits/stdc++.h>
using namespace std;
#define cfalse cin.tie(0)->sync_with_stdio(0)
const int maxn = 10005;
string s;
long long buk[maxn], num = 0;
//vector<int>mp;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		if('0' <= s[i] && s[i] <= '9'){
//			mp.push_back(s[i] - '0');
			buk[s[i] - '0']++;
			num++;
		}
	}
	for(int i = 9; i >= 0; i--){
		for(int j = 0; j < buk[i]; j++){
			cout << i;
			num--;
		}
	}
	return 0;
} 
