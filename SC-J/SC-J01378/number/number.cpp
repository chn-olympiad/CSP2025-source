#include<bits/stdc++.h>
using namespace std;
int a[11];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i])){
			a[s[i]-48]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=a[i];j;j--){
			cout<<i;
		}
	}
	return 0;
}
