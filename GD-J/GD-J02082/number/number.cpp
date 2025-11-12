#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;	cin>>s;
	vector<int> a;
	for(auto c : s){
		if(c >= '0' && c <= '9')	a.pb(c - '0');
	}
	sort(a.begin(), a.end());
	if(a[a.size() - 1] == 0){
		cout<<"0\n";
		return 0;
	}
	for(int i = a.size() - 1;i >= 0;i--){
		cout<<a[i];
	}
	return 0;
}
