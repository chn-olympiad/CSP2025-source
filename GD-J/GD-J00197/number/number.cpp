#include <bits/stdc++.h>
using namespace std;


int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int l[10] = {};
	cin >> s;
	for(int i = 0,x;i < s.size();i ++){
		x = s[i] - '0';
		if(x >= 0 && x <= 9) l[x] ++;
	}
	for(int i = 9;i >= 0;i --)
		for(int j = 0;j < l[i];j ++)
			cout << i;
	return 0;
} 
