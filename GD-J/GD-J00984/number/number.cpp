#include<bits/stdc++.h>
#define i64 long long
using namespace std;

int a[1000001];

bool cmp(int x,int y){
	return x > y;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	i64 j = 0;
	for(int i = 0; i <= s.length(); i++) {
		char c; c = s[i];
		if(c <= '9' && c >= '0') {
			a[j] = c - '0';
			j++;
		}
	}
	
	sort(a,a+j,cmp);
	
	for(i64 i = 0; i < j; i++) {
		cout << a[i];
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

