#include <bits/stdc++.h>
using namespace std;
string s;
int a[10];
int main(){
	preopen("seat.in ","in","r") stdin;
	preopen("seat.out","out","w") stdout;
	cin>>s;
	for(int i=1;i<=s.size();i++){
		if(s[i]>='1'&&s[i]<=9){
			a[s[i]]++;
		}
	}
	for(int i=9;i>=0;i--){
		if(a[i]!=0){
			for(int j=1;j<=a[i];j++){
				cout<<i;
			}
		}
	}
	return 0;
} 
