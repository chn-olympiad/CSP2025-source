#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,s1="";
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if(s[i]<='9'&&'0'<=s[i]){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			cout<<i;
		}
	} 
	return 0;
} 