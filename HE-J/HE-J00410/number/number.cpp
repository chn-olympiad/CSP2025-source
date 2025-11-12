#include<iostream>
#include<algorithm>
#include<iomanip>
#include<string>
using namespace std;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	vector<int> numbers;
	for(char c:s){
		if(c>='0'&&c<='9'){
			numbers.push_back(c-'0');
		}
	}
	sort(numbers.begin(),numbers.end());
	for(int i = numbers.size()-1;i>=0;i--){
		cout << numbers[i];
	}
	return 0;
}
