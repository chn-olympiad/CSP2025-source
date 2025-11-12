#include <iostream>
using namespace std;
int xin[1028];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	for(int i = 0;i < int(s.size());i ++)
		if('0' <= s[i] && s[i] <= '9')xin[s[i] - '0'] ++;
	for(int i = 9;i >= 0;i --)
		for(int j = 1;j <= xin[i];j ++)
			cout << i;
	return 0;
} 
