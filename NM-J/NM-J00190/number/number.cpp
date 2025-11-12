#include<bits/stdc++.h>
using namespace std;
string s;
int nim[10]={0,0,0,0,0,0,0,0,0,0};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	for(int a=0;a<s.size();a++){
		if(s[a]>='0'&&s[a]<='9') nim[s[a]-'0']++;
	}
	for(int a=9;a>=0;a--){
		while(nim[a]>0) {
			cout<<a;
			nim[a]--;
		}
	}
	return 0;
} 
