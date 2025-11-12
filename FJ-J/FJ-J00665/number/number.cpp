#include<bits/stdc++.h>
using namespace std;
char s[1010]={};
int main(){
    freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int len;
	for(int i=1;i<=len;i++){
		cin>>s[i];
	}
	for(int i=1;i<=len;i++){
		if(!s[i]>='0'&&!s[i]<='9'){
			s[i]=s[i+1];
			len--;
	    }
	}
	sort(s,s+len);
	cout<<s;
	return 0;
}