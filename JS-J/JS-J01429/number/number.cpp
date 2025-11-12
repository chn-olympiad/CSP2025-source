#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e6 + 10;

string s;
vector<char> v;

bool cmp(char a, char b){
	return a > b;
}

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for(int i = 0; i < (int)s.size(); i++){
		if(s[i] >= '0' && s[i] <= '9')
			v.push_back(s[i]);
	}
	sort(v.begin(), v.end(), cmp);
	for(int i = 0; i < (int)v.size(); i++)
		cout << v[i];
}
