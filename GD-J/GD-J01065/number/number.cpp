#include<bits/stdc++.h>
using namespace std;
string s;
int  n[11];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]=='0'){
			n[0]++;
		}else if(s[i]=='1'){
			n[1]++;
		}else if(s[i]=='2'){
			n[2]++;
		}else if(s[i]=='3'){
			n[3]++;
		}else if(s[i]=='4'){
			n[4]++;
		}else if(s[i]=='5'){
			n[5]++;
		}else if(s[i]=='6'){
			n[6]++;
		}else if(s[i]=='7'){
			n[7]++;
		}else if(s[i]=='8'){
			n[8]++;
		}else if(s[i]=='9'){
			n[9]++;
		}
	}
	for(int i=9;i>=0;i--){
		while(n[i]--){
			cout<<i;
		}
	}
	return 0;
} 
