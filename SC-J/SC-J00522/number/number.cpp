#include<bits/stdc++.h>
using namespace std;
const int N = 10;
inline void read(int& x){
	x = 0;
	bool f = 0; 
	char c = getchar();
	while(c < '0' || c > '9'){
		f = (c == '-');
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = (x << 3) + (x << 1) + (c & 15);
		c = getchar();
	}
	if(f) x = -x;
}
int record[N];
int main(){
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);
	string s;
	cin >> s;
	int n = s.length();
	s = ' ' + s;
	for(int i = 1;i <= n;++ i){
		if(s[i] >= '0' && s[i] <= '9'){
			++ record[s[i] - '0'];
		}
	}
	for(int i = 9;i >= 0;-- i){
		while(record[i]){
			cout << i;
			-- record[i];
		}
	}
	return 0;
} 