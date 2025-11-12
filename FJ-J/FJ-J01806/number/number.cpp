#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 5;
string s;
int x, a[N];
stack <int> st;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for(int i = 0;i < s.size();i++){
		if('0' <= s[i] && s[i] <= '9'){
			x++;
			a[x] = s[i] - '0';
		}
	}
	sort(a + 1, a + x + 1);
	for(int i = 1;i <= x;i++){
		st.push(a[i]);
	}
	for(int i = 1;i <= x;i++){
		cout << st.top();
		st.pop();
	}
	return 0;
}
