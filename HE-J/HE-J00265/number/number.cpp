#include<bits/stdc++.h>
using namespace std;
string str;
int a[1000],b,c;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(int i=0;i<str.size();i++){
		if(str[i]-48<10){
			c++;
			a[str[i]-48]++;
			b=max(b,str[i]-48);
		}
	}
	for(int j=10;j>0;j--){
		for(int k=0;k<a[j];k++){
			cout<<j;
		}
	}
	return 0;
} 
