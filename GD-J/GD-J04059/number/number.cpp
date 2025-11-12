#include<bits/stdc++.h>
using namespace std;
string str;
int num[12];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(int i=0;i<str.size();i++){
		if(str[i]<='9'&&str[i]>='0') num[int(str[i]-'0')]++;
	}
	for(int i=9;i>=0;i--){
		if(num[i]==0) continue;
		for(int j=1;j<=num[i];j++) cout<<i;
	}
	return 0;
} 
