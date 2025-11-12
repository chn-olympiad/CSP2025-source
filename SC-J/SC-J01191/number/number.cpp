/*
把所有数字挑出来 o(s) 1e6
存到桶里 

输出桶 o(s) 1e6 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int t[10];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			t[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(t[i]>0){
			cout<<i;
			t[i]--;
		}
	}
	return 0;
}