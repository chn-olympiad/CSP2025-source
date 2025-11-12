#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>

using namespace std;

bool cmp(char a, char b){
	return a > b;
}

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	char n[1000005];
	int cnt=0;
	cin >> s;
	for(int i=0; i<s.size(); i++){
		if(s[i] >= '0' && s[i] <='9'){
			n[cnt] = s[i];
			cnt ++ ;
		}
	}
	sort(n, n+cnt, cmp);
	cout << n;
	return 0;
}
