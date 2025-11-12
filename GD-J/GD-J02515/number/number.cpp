#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

bool cmp(long long a,long long b){
	return a > b;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	long long s_len = s.length();
	string c1l = "",c2l = "",c3l = "",c4l = "",c5l = "",c6l = "",c7l = "",c8l = "",c9l = "",c0l = "";
	while(s_len--){
		if(s[s_len] == '0') c0l += '0';
		if(s[s_len] == '1') c1l += '1';
		if(s[s_len] == '2') c2l += '2';
		if(s[s_len] == '3') c3l += '3';
		if(s[s_len] == '4') c4l += '4';
		if(s[s_len] == '5') c5l += '5';
		if(s[s_len] == '6') c6l += '6';
		if(s[s_len] == '7') c7l += '7';
		if(s[s_len] == '8') c8l += '8';
		if(s[s_len] == '9') c9l += '9';
		
	}
	cout << c9l << c8l << c7l << c6l << c5l << c4l << c3l << c2l << c1l << c0l;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
