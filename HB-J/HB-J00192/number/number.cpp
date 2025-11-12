#include <bits/stdc++.h>
using namespace std;
string s;
char number[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			number[s[i]-'0']++;
		}
	}
	for(int j=9;j>-1;j--) for(int i=0;i<number[j];i++) cout<<j;
	return 0;
}
