#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> num;
string s;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> s;
	for(char c : s){
		if(c >= '0' && c <= '9')
			num.push_back(c - '0');
	}
	sort(num.begin(), num.end());
	if(!num.back()){
		puts("0");
		return 0;
	}
	for(int i = num.size() - 1; i >= 0; i--)
		cout << num[i]; 
	return 0;
}
