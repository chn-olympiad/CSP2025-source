#include<bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;

int n;
string s;
vector<char> v;

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	s = '#' + s;
	n = s.length();
	for(int i = 1; i <= n; i++){
		if(s[i] >= '0' && s[i] <= '9'){
			v.push_back(s[i]);
		}
	}	
	sort(v.begin(), v.end());
	int siz = v.size();
	for(int i = siz - 1; i >= 0; i--){
		cout << v[i];
	}
	cout << endl;
	return 0;
}
