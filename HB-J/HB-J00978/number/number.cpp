#include<bits/stdc++.h>
using namespace std;
string s;
vector<int> a;
bool cmp(int x , int y){
	return x > y;
}
int main(){
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);
	cin >> s;
	for (auto i : s){
		if (i >= '0' && i<='9') a.push_back(i - '0');
	}
	sort(a.begin() , a.end() , cmp);
	for (auto i : a) cout << i;
	return 0;
}
