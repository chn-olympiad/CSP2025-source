#include <bits/stdc++.h>
using namespace std;
string str;
char num[1000005];
int l;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> str;
	for(int i = 0; i < str.size(); i++){
		if(str[i] >= '0' && str[i] <= '9') num[l++] = str[i];
	}
	sort(num, num + l, [](char a, char b){
		return a > b;
	});
	cout << num;
	return 0;
}

