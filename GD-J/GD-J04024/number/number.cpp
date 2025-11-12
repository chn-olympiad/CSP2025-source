#include <bits/stdc++.h>
using namespace std;
string s;
bool check(char c){
	return c>='0'&&c<='9';
}
int num[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(char c:s){
		if(check(c)) num[c-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=num[i];j++) cout << i;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
