#include<bits/stdc++.h>
using namespace std;
string s; int bin[1000006];
int main(){
	freopen("number.in","r",stdin); freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i])) bin[s[i]-48]++;
	}
	for(int i=9;i>=0;i--)
		while(bin[i]--) cout<<i;
	fclose(stdin); fclose(stdout);
	return 0;
}