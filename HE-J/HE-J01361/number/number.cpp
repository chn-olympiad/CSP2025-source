#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std; 

bool cmp(char a, char b){
	return a>b;
}
char s[1000005], n[1000005];
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int x=0;
	cin >> s;
	for(int i=0;s[i];i++){
		if(s[i]>='0'&&s[i]<='9'){
			n[x] = s[i];
			x++;
		}
	}
	sort(n, n+x, cmp);
	cout << n;
	return 0;
}
