#include <bits/stdc++.h>
using namespace std;
map<char,int> f;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') f[s[i]]++;
	}
	for(char c='9';c>='0';c--){
		for(int i=1;i<=f[c];i++){
			putchar(c);
		}
	}
	return 0;
}
