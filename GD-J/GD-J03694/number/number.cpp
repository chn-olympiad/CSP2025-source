#include <bits/stdc++.h>
using namespace std;

string s;

bool cmp(int a, int b){
	return a > b ? 1 : 0;
}
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	cin >> s;
	
	vector <int> tmp;
	for (int i=0;i<s.size();i++){
		if ('0' <= s[i] && s[i] <= '9') tmp.push_back(s[i]-'0');
	}
	
	sort(tmp.begin(), tmp.end(), cmp);
	for (int i : tmp) cout << i;
	
	return 0;
} 
