#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
string s;
vector<int> vec;
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(char c: s) if('0'<=c&&c<='9') {
		vec.push_back(c-'0');
	}
	sort(vec.begin(),vec.end(),greater<int>());
	for(int& i: vec)
		cout<<i;
	return 0;
}

