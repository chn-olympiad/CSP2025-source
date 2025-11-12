#include<bits/stdc++.h>
using namespace std;
int bin[150];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	for(int i=0;i<s.size();i++){
		bin[s[i]-'0']++;
	} 
	
	for(int i=10;i>=0;i--){
		while(bin[i]>0){
			cout<<i;
			bin[i]--;
		}
	} 
	
	return 0;
}
