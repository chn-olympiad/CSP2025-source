#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen(number.in);
	freopen(number.out);
	string s;
	int a[10]={};
	cin>>s;
	for(int i=0;i<sizeof(s);i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		if(a[i]>0){
			for(int j=a[i];j>0;j--){
				cout<<i;
			}
		} 
	}
}
