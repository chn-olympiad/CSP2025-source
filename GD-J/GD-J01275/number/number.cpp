#include <bits/stdc++.h>
using namespace std;

const int maxn=10;
int ncnt[maxn];
string s,ans;

void open(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
}
void close(){
	fclose(stdin);
	fclose(stdout);
}
void input(){
	cin >> s;
}
void solve(){
	for(int i=0;i<(int)s.length();i++){
		if('0'<=s[i] && s[i]<='9'){
			ncnt[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=ncnt[i];j++){
			ans+=char(i+'0');
		}
	}
}
void output(){
	cout << ans;
}
int main(){
	open();
	input();
	solve();
	output();
	close();
	return 0;
}
/*
Test:
test-1 pass
test-2 pass
test-3 pass
test-4 pass 
*/
