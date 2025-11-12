#include <bits/stdc++.h>
using namespace std;
int a, i, j, f[75];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(i=0;i<s.size();i++){
		a=s[i]-'0';
		if(0<=a&&a<=9)++f[a];
	}
	for(i=9;i>=0;i--){
		for(j=f[i];j;j--)cout<<i;
	}
	return 0;
}

