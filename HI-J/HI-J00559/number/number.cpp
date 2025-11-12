#include<bits/stdc++.h>
using namespace std;
int a[1000006];
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int ln =  0;
	for(int i =0;i < s.size(); i++){
		if(s[i] >='0'&& s[i]<='9'){
			int y = s[i]-'0';
			a[++ln]=y;
		}
	}
	sort(a+1,a+ln+1);
	for(int i = ln; i >= 1;i--) printf("%d",a[i]);
	return 0;
} 
