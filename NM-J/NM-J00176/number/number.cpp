#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	vector<int> n;
	cin >> s;
	for (int i = 0; i < s.size(); i++){
		if (s[i]>='0' && s[i]<='9'){
			n.push_back(s[i]-'0');
		}
	}
	sort(n.begin(), n.end(), greater<int>());
	bool flag=1;
	for (int i = 0; i < n.size(); i++){
		if (flag){
			if (n[i] != 0){
				flag = 0;
				cout << n[i];
			}
			continue;
		}
		cout << n[i];
	}
	cout << endl;
	return 0;
} 
