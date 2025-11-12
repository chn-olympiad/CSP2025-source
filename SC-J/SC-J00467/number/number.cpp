#include<bits/stdc++.h>
using namespace std;
using ll = long long; 
int cmp(char x, char y){
	return x > y;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	vector<char> ve;
	ll ans = 0, t = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] >= '0' && s[i] <= '9'){
			ve.push_back(s[i]);
		}
	}
	sort(ve.begin(), ve.end(), cmp);
	for(auto i : ve){
		cout << i;
	}
	return 0;
}