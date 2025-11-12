#include<bits/stdc++.h>
#include<iostream>
using namespace std;
string s;
int m=0,a[1000000];

int main(){
	//std::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r","stdin");
	freopen("number.out","w","stdout");
	
	cin>>s;

	for(int i =1;i<=s.length();i++){
		if('0'<=int(s[i]) and int(s[i]<='9')){
			m++;
			a[m]=int(s[i])-'0';
		}
	}
	sort(a+1,a+m+1);
	if(a[m]==0){
		cout<<0;
		return 0;
	}
	for(int i =m;i>=1;i--){
		cout<<a[i];
	}
	
} 

