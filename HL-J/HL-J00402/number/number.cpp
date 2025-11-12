#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	vector <int> a;
	string s;
	cin >> s;
	for(int i = 0;i<s.size();i++){
		if(int(s[i]) >= '0' && int(s[i])<='9'){
			a.push_back(s[i]);
		}
	}
	sort(a.begin(),a.end(),greater<int>());
	if(a[0]-48 != 0){
		for(int i = 0;i<a.size();i++){
			cout << (a[i]-48);
		}
	}
	else{
		cout << 0;
	}
	return 0;
}
