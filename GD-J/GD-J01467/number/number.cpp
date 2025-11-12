#include<bits/stdc++.h>
using namespace std;

string s;
int m[2000000] , ans[2000000];

int main(){
	cin >> s;
	int cnt = 1;
	for(int i = 0;i < s.size();++i){
		if(s[i] - '0' >= 0 && s[i] - '0' <= 9){
			m[++cnt] = s[i] - '0';
		}
	}
	sort(m+1,m+cnt+1);
	for(int i = cnt;i > 1;--i){
		cout << m[i];
	}
	return 0;
}

