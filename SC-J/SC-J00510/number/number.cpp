#include<bits/stdc++.h>
using namespace std;
long long nu[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			nu[s[i]-'0']++;
		}
	}bool flag=true;
	for(int i=1;i<=9;i++){
		 if(nu[i]>0){
		 	flag=false;
		 }
	}if(flag){
		cout<<0;
		return 0;
	}for(int i=9;i>=0;i--){
		if(nu[i]>0){
			cout<<i;
			nu[i]--;
			i++;
		}
	}
	return 0;
}