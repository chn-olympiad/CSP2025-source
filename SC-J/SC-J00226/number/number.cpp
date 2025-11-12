#include<bits/stdc++.h>
using namespace std;

bool cmp(const char &a ,const char &b){
	return a > b;
}

int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,t="";
	cin>>s;
	for(char c : s){
		if(c>='0' && c<='9') t+=c;
	}
	sort(t.begin(),t.end(),cmp);
	cout<<t;
	return 0;
}