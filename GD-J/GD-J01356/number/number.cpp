#include <bits/stdc++.h>
using namespace std;
string str;
int t[15];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >>str;
	for(int i=0;i<str.size();i++){
		char ch=str[i];
		if(ch>='0'&&ch<='9') t[ch-'0']++;
	}
	for(int i=9;i>=0;i--)
		while(t[i]--) cout <<i;
	return 0;
}
