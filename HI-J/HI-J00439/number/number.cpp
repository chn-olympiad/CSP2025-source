#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
using namespace std;
int main(){
	//ifstream fin("number.in");
	//ofstream fout("number.out");
	string s;
	cin >> s;
	int num = 0;
	for (int i =1;i <= s.size();i++){
		if (s[i] >= 0 && s[i] <= 9){
			num = s[i];
			cout << num;
		}
		cout << num;
	}
	return 0;
} 
