#include<bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 100050;

bool cmp(char a, char b){
	return a > b;
}

string s;
vector<char> ans;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for(char i : s){
		if(isdigit(i)){
			ans.push_back(i);
		}
	} 
	sort(ans.begin(), ans.end(), cmp);
	for(char i : ans)
		cout << (char)i; 
	return 0;
}