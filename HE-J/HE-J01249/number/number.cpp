#include <bits/stdc++.h>
using namespace std;

char s[1000010];
int p[1000010];

int main(){
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);
	cin >> s;
	for(int i = 0 ; i < strlen(s) ; i++)
		if(s[i] >= '0' && s[i] <= '9') 
			p[++p[0]] = s[i] - '0';
	sort(p + 1 , p + p[0] + 1);
	for(int i = p[0] ; i >= 1 ; i--)
		cout << p[i];
	return 0;
}

