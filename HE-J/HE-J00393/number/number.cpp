#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	getline(cin,s);
	int len=s.size();
	for(int i=1;i<=len-1;i++){
		if(s[i]>='0' && s[i]<='9'){
			if(s[i]<s[i+1] && s[i+1]>s[i]) swap(s[i],s[i+1]);
			cout<<s[i];
		}
	}
	return 0;
}
