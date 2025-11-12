#include<string>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool cmp(char a,char b) {
	return a>b;
}

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string a,b;
	cin>>a;
	for(char c:a) {
		if(c>='0'&&c<='9') b+=c;
	}
	sort(b.begin(),b.end(),cmp);
	cout<<b;
}
