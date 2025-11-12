#include<bits/stdc++.h>
using namespace std;
string s;
int a[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<(int)s.size();++i){
		if(s[i]>='0'&&s[i]<='9'){
			++a[int(s[i]-'0')];
		}
	}
	for(int i=9;i>=0;--i){
		char ch=char(i+'0');
		for(int j=1;j<=a[i];++j){
			putchar(ch);
		}
	}
	return 0;
} 
