#include <bits/stdc++.h>
using namespace std;
int a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;	cin>>s;
	for(int i=0 ; i<s.size() ; i++){
		if(s[i]>='0' && s[i]<='9'){
			int n=s[i]-48;
			a[n]++;
		}
	} 
	for(int i=9 ; i>=0 ; i--){
		while(a[i]){
			cout<<i;
			a[i]--; 
		}
	} 
	return 0;
}
