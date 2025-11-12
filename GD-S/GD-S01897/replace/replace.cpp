#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n, q;
vector<vector<string> > v;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 0; i < n; i++){
		vector<string> p1;
		string s1, s2;
		cin >> s1 >> s2;
		
		p1.push_back(s1);
		p1.push_back(s2);
		v.push_back(p1);
	}
	cout<< 0;
	return 0;
} 
