#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

string s;
vector <int> number;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for (int i = 0;i < s.size();i++){
		if (s[i] >= '0' and s[i] <= '9'){
			number.push_back(int(s[i] - '0'));
		}
	}
	sort(number.begin(),number.end());
	for (int i = number.size() - 1;i >= 0;i--){
		cout << number[i];
	}
} 
