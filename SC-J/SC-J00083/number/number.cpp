#include<bits/stdc++.h>
using namespace std;
string str;
int len,book[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	len=str.size();
	for(int i=0;i<len;i++){
		if(str[i]>='0'&&str[i]<='9'){
			book[str[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=book[i];j++){
			cout<<i;
		}
	}
	return 0;
}