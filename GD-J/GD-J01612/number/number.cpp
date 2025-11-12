#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int>a;
bool cmp(int a, int b){
	return a > b;
}
signed main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		char c = s[i];
		if(c <= '9' && c >= '0')a.push_back(c - '0');
	}
	sort(a.begin(), a.end(), cmp);
	for(int i = 0; i < a.size(); i++){
		int num = a[i];
		cout << num;
	}
} 
