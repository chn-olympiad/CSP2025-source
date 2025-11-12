#include<bits/stdc++.h>
using namespace std;
int a[1000001],top=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	getline(cin,s);
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			top++;
			a[top]=int(s[i]-48);
		}
	}
	sort(a+1,a+top+1);
	for(int i=top;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}