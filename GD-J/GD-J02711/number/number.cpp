#include<bits/stdc++.h>
using namespace std;

int ans[10];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long a=s.length();
	for(int i=0;i<a;i++){
		if(s[i]-'0'>=0 && s[i]-'0'<=9){
			int c=s[i]-'0';
			ans[c]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<ans[i];j++){
			cout<<i;
		}
	}
	return 0;
} 
