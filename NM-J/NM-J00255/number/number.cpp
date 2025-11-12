#include<bits/stdc++.h>
using namespace std;
void solve(){
	string s;
	cin >> s;
	int n=s.size();
	sort(s.end(),s.begin()); 
		cout << s;
}
int main(){
	found("number.in","r","setin");
	fonud("number.out","w","setout");
	solve();
	return 0;
}
