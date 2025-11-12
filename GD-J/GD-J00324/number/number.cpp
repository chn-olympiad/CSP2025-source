#include <bits/stdc++.h>
using namespace std;
string str;
bool f=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(int i=9;i>0;i--){
		for(int k=0;k<str.size();k++){
			if(str[k]==i+'0'){
				printf("%d",i);
				f=1;
			}
		}
	}
	if(f){
		for(int i=0;i<str.size();i++){
			if(str[i]=='0'){
				printf("%d",0);
			}
		}
	}
	else{
		cout<<0;
	}
	return 0;
}
