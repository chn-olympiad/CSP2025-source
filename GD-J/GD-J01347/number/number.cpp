#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;
int a[1000005];
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	long long n = s.size();
	long long cnt = 0;
	for (int i=0;i < n;i++){
		if ('0' <= s[i] && s[i] <= '9'){
			cnt++;
			a[cnt] = int(s[i])-48;
		}
	}
	sort (a+1, a+cnt+1);
	for (int i=cnt;i>=1;i--){
		cout << a[i];
	}
	return 0;
} 
