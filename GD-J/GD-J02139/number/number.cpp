#include<bits/stdc++.h>
using namespace std;

vector<char> b;

bool compare(char c,char d) {
	return c>d; 
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	string a;
	cin>>a;
	for(int i=0;i<(long long)a.length();i++) {
		if(a[i]>='0'&&a[i]<='9') b.push_back(a[i]);
	}
	
	sort(b.begin(), b.end(), compare);
	
	for(auto i:b) cout<<i;
	
	return 0;
}
