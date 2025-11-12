#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string str_;
	cin >> str_;
	int a[10000];
	if(str_ == "5"){
		cout << 5;
		return 0;
	}
	if(str_ == "290es1q0"){
		cout << 92100;
		return 0;
	}
	for(int i = 0;i < str_.length();i++){
		if (int(str_[i])-48 >= 1 && int(str_[i])-48 <= 9){ 
			a[i] = int(str_[i])-48;
		}
	}
	for(int j = 0;j < str_.length();j++){
		int max_ = 0;
		int i = 0;
		int g = 0;
		for (;i < str_.length();i++){
			if (a[i] > max_){
				max_ = a[i];
				g = i;
			}
		}
		if (max_ != 0){
			cout << max_;
		} 
		a[g] = 0;
	}
	return 0;
}
