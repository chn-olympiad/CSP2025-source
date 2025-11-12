#include<bits/stdc++.h>
using namespace std;
string s;
char c[1000001];
int num[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	string q="";
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			q+=s[i];
			char d=s[i]-'0';
			num[d]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=num[i];j++){
			cout<<i;
		}
	}
	return 0;
}
