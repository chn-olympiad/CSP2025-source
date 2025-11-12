#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	vector<int> v;
	for(int i = 0;i < s.size();i++){
		char ch = s[i];
		if(ch>='0'&&ch<='9'){
			v.push_back(ch-'0');
		}
	}
	sort(v.begin(),v.end());
	for(int i = v.size()-1;i >= 0;i--){
		cout << v[i];
	}
	return 0;
} 
