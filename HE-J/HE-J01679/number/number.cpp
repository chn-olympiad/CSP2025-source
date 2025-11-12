#include<bits/stdc++.h>
using namespace std;
string s;
const int maxA = 1e8+5;
string end;
int a[maxA];
int j = 0;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0; i<s.length(); i++) {
		if(s[i]>='0'&&s[i]<='9') {
			a[j]+=s[i]-'0';
			j++;
		}
	}
	sort(a,a+j);
	for(int i = 0; i<=j; i++) {
		char ss=a[i]+'0';
		end+=ss;
	}
	for(int i = j-1;i>=0;i--){
		cout << end[i];
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
