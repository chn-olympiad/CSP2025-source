#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a[1005];
	int b[1005];
	int manx=0;
	for(int i=0;i<s.length();i++){
		if(s[i]==1 || s[i]==2 ||s[i]==3 ||s[i]==4 ||s[i]==5 ||s[i]==6 ||s[i]==7 ||s[i]==8 ||s[i]==9){
			a[i]=s[i];
		}
	}
	for(int i=0;i<s.length();i++){
		cout<<a[i];
	}
	return 0;
}
