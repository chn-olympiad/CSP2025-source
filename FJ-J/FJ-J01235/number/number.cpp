#include<bits/stdc++.h>
using namespace std;
string s;
string a;
int main(){
	cin>>s;
	for(int i=0;i<=s.length();i++){
		if(s[i]>='1' and s[i]<='9'){
			a[i]=s[i];
			cout<<a[i];
		}
	}
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	return 0;
} 
