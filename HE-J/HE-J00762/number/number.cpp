#include<bits/stdc++.h>
using namespace std;
int digit[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.length();
	if(len==1){
		cout<<s;
		return 0;
	}
	int t=0;
	for(int i=0;i<=len;i++){
		if(s[i] >= '0' && s[i] <= '9'){
			digit[i]=s[i]-'0';
		}
		else{
			t++;
		}
	}
	sort(digit,digit+len);
	for(int i=len-1;i>=t-1;i--){
		cout<<digit[i];
	}
	return 0;
}
