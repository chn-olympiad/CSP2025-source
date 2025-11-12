#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	for (char i:s){
		if ('0'<=i && i<='9'){
			a.push_back(i-'0');
		}
	}
	sort(a.begin(),a.end(),greater<int>());
	for (int i:a){
		printf("%d",i);
	}
	return 0;
}
