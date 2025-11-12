#include<bits/stdc++.h>
using namespace std;
using LL = long long;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	string s;cin >> s;
	vector<int> A;
	for(char c : s){
		if(isdigit(c)) A.push_back(c - '0');
	}
	sort(begin(A), end(A), greater<>());
	for(int l : A) cout << l;
	return 0;
}
/*




*/