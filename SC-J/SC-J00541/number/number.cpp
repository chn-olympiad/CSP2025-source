#include<bits/stdc++.h>
using namespace std;
int to[20]; 
string str;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(int i=0;i<str.size();i++){
		if(str[i]<='9'&&str[i]>='0'){
			to[str[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=to[i];j++){
			cout<<i;
		}
	}
	return 0;
} 