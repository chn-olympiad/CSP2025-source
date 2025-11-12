#include<bits/stdc++.h>
#include<iostream>
using namespace std;
string s;
int h[1000001],o;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>=0){
			h[o]=s[i]-'0';
			o++;
		}
	}
	sort(h,h+o,cmp);
	for(int i=0;i<o;i++){
		cout<<h[i];
	}
	return 0;
}

