#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
signed main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios :: sync_with_stdio(0),cin.tie(0),cout.tie(0);
    string s;
    cin >> s;
    vector<int> numbers;
    for(int i=0;i<s.size();i++) {
    	if(s[i] >= '0' && s[i] <= '9') {
    		numbers.push_back(s[i] - '0');
		}
	}
	sort(numbers.begin(),numbers.end(),greater<int>());
	for(int i=0;i<numbers.size();i++) {
		cout << numbers[i];
	}
	return 0;
}