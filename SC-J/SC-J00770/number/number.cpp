#include<iostream>
#include<string>
using namespace std;

string s;
int nums[10];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin>>s;
	int sz = s.size();
	for(int i=0;i<sz;++i) {
		if('0'<=s[i] && s[i]<='9') {
			++nums[s[i]-'0'];
		}
	}
	for(int i=9;i>=0;--i) {
		for(int j=1;j<=nums[i];++j) {
			cout<<i;
		}
	}
	return 0;
} 