#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

string s;

int a[N];

int b[N];

char d[N];

bool cmp(int a,int b){
	return a>b;
}

int main() {
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin >> s;
	int cnt = 1;
	for (int i = 0 ; i <= s.size() ; i ++) {
		if (s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9' || s[i] == '0'){
			d[cnt] = s[i];
			cnt++;
		}
	}
	

	for (int i = 1 ; i < cnt ; i ++) {
		b[i] = d[i] -'0';
	}
	sort(b+1,b+1+cnt,cmp);
	
	for (int i = 1; i < cnt ; i ++) {
		cout << b[i] ;
	}
	
	return 0;
}
