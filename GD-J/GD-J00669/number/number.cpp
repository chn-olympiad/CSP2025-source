#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s; cin >> s;
	int h=s.size();
	int a[25]={};
	for(int i=0;i<h;i++){
		if(isdigit(s[i])){
			int t=s[i]-48;
			a[t]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<a[i];j++){
			cout << i;
		} 
	}
	return 0;

} 
