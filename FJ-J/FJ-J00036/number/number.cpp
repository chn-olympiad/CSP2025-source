#include<bits/stdc++.h>
using namespace std;
string s;
long long sum,ans,wz;
bool tmp;
int s1[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	for(int i=0;i<s.length();i++){
		if(s[i]>='0' && s[i]<='9'){
			s1[s[i]-'0']++; 
		}
	}
	for(int i=9;i>=1;i--){ 
		for(int j=1;j<=s1[i];j++){
			cout<<i;
			tmp=1;
		}
	}
	if(tmp==0){
		cout<<0;
	}else{
		for(int i=1;i<=s1[0];i++){
			cout<<0;
		}
	}
	return 0;
}
