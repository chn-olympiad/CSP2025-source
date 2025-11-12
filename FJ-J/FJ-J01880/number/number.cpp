#include<bits/stdc++.h>
using namespace std;
string s;
int k[100086];
int shuwei;
int ans;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i])){
			k[shuwei]=s[i]-48;
			shuwei++;
		}
	}
	sort(k,k+shuwei);
	for(int i=shuwei-1;i>=0;i--){
		cout<<k[i];
	}
	return 0;
}
