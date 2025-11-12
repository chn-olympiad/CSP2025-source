#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
string s;
vector<int>a;

bool cmp(int x, int y){
	return x > y;
}

int main(){
	
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	cin >> s;
	for(int i = 0; i < s.size(); ++i){
		if(s[i] >= '0' && s[i] <= '9') a.push_back(s[i] - '0');
	}
	sort(a.begin(), a.end(), cmp);
	if(a[0] == 0){
		cout << 0;
		return 0;
	}
	for(int i : a){
		cout << i;
	}
	return 0;
}