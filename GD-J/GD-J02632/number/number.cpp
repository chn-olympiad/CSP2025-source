#include <bits/stdc++.h>
using namespace std;
string s;
vector <int> v;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdin);
	cin >> s;
	for (int i = 0; i < s.size(); i++){
		if (s[i] >= 'a' && s[i] <= 'z'){
			continue;
		}else{
			v.push_back(int(s[i]-'0'));
		}
	}
	sort(v.begin(),v.end());
	for(int i = v.size()-1; i >= 0; i--){
		cout << v[i];
	}
	return 0;
}
