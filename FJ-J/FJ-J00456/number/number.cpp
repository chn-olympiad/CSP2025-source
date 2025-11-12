#include <bits/stdc++.h>
using namespace std;
bool check(char c){
	int x = c - '0';
	if(x >= 0 && x <= 9) return true;
	return false;
}
bool cmp(int x , int y){
	return x > y;
}
int main(){
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);
	string s;
	cin >> s;
	vector<int> w;
	for(int i = 0 ; i < s.size() ; i ++){
		if(check(s[i])){
			w.push_back(s[i] - '0');
		}
	}
	sort(w.begin() , w.end());
	while(w.size() > 1 && w.back() == 0) w.pop_back();
	reverse(w.begin() , w.end());
	for(auto x : w) cout << x;
	return 0;
}
