#include<bits/stdc++.h> 
using namespace std;
const int N=1e3+10;
int t[N];
int main(){
	string s;
	cin>>s;
	for(int i=0;i<=s.size()-1;i++){
		if(s[i]>='0'&&s[i]<='9'){
			t[s[i]-'0']++;
		}
	} 
	for(int i=9;i>=0;i--){
		for(int j=1;j<=t[i];j++){
			cout<<i;
		}
	}
	
	
	return 0;
}