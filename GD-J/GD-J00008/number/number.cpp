#include<bits/stdc++.h> 
using namespace std;
string s;
int cnt,t[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		t[s[i]-48]++;
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<t[i];j++){
			cout<<i;
		}
	}
	
	return 0;
}
