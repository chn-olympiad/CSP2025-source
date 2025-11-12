#include<bits/stdc++.h>
using namespace std;
string s;
int a[1010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	bool tmp=false; 
	for(int i=9;i>=0;i--){
		if(a[i] && i==0 && tmp==false){
			cout <<0;
			return 0;
		}
		while(a[i]--){
			tmp=true;
			cout <<i;
		}
	}
	return 0;
} 