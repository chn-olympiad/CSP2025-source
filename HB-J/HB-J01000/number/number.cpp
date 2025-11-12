#include<bits/stdc++.h>
using namespace std;
string s;
int m[1000001];
int i;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int a=s.length();
	if(a==1){
	    cout<<s;
	    return 0;
	}
	for(i=0;i<=a;i++){
		if(s[i]>='0' && s[i]<='9'){
			m[i]=s[i]-'0';
		}
	}
	for(i=0;i<a;i++){
		cout<<m[i];
	}
	return 0;
}
