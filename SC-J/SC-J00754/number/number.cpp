#include<bits/stdc++.h>
using namespace std;
int a[10],cnt;
string s;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	cnt=s.size();
	for(int i=0;i<cnt;++i){
		if(0<=(s[i]-'0')&&(s[i]-'0')<=9){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;--i){
		while(a[i]){
			cout<<i;
			a[i]--;
		}
	}
	return 0;
}