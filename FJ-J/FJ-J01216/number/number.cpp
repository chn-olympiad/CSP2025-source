#include<bits/stdc++.h>
using namespace std;
long long ans = 0;
vector<int> now;
int main(){
	//fopen("r","number.in");
	//fopen("w","number.out");
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++){
		if (isdigit(s[i])){
			now.push_back(s[i]-'0');
		}
	}
	sort(now.begin(),now.end());
	for (int i = now.size()-1; i >= 0; i--){
		ans *= 10;
		ans += now[i];
	}
	cout << ans;
	return 0;
}
