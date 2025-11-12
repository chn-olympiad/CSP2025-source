#include<bits/stdc++.h>
using namespace std;
string s;
int shu[9],e;
int main(){
	cin>>s;
	for(int i=0;i<=s.size;i++){
		e=shu[i]-'0';
		if(e>=0 and e<=9){
			shu[e]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<shu[i];j++){
			cout<<shu[i]
		}
	}
	return 0;
}
