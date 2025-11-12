#include<bits/stdc++.h>
using namespace std;
string s;
vector<int> a;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin>>s;
	for(auto i : s){
		if(isdigit(i)){
			a.push_back(i - '0');
		}
	}
	sort(a.begin(), a.end(), greater<int>());
	for(int i : a){
		cout<<i;
	}
	puts("");
	return 0;
}
