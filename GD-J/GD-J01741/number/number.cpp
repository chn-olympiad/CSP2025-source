#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
string s;
int t[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int rp = 0;rp < s.size();rp++) if(s[rp]>='0' && s[rp]<='9') t[s[rp]-'0']++;
	for(int wa = 9;wa >= 0;wa--) while(t[wa]--) cout<<wa;
	return 0;
}
