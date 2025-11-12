#include <bits/stdc++.h>
using namespace std;
string s;
int t[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	s=" "+s;
	int l=s.size();
	for(int i=1;i<=l;i++){
		if(s[i]<='9'&&s[i]>='0')
			t[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=t[i];j++)
			cout<<i;
	}
	return 0;
} 
