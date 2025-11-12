#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	vector<long long> num;
	
	string str;
	cin >> str;
	for(char i:str){
		if('0' <= i && i <= '9'){
			num.push_back(i-'0');
		}
	}
	sort(num.begin(), num.end());
//	cout << num.size() << endl;
	long long sum=0;
	for(int i=num.size()-1; i >= 0; i--){
//		sum = sum*10 + num[i];
		cout << num.at(i);
	}
	return 0;
}
