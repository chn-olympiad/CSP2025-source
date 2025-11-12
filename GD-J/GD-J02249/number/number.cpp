#include <iostream>
#include <cstring>
using namespace std;
int hump[15];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for (int i = 0;i < s.size();i++){
		if (s[i] >= '0' && s[i] <= '9'){
			hump[s[i]-'0']++;
		}
	}
	bool flag = true;
	for (int i = 9;i >= 1;i--){
		if (hump[i] > 0) flag = false;
	}
	for (int i = 9;i >= 0;i--){
		if (i == 0 && flag){
			cout << 0;
			break;
		}
		for (int j = 1;j <= hump[i];j++){
			cout << i;
		}
	}return 0;
} 
