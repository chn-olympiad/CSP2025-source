#include<bits/stdc++.h>
using namespace std;
string s;
long long ly[20];
int main(){
	freopen("number.in","r".stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i=0;i<s.size();i++){
		if(s[i]-0>=48&&s[i]-0<=57){
			ly[s[i]-48]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=ly[i];j>0;j--){
			cout << i;
		}
	}
	return 0;
} 
