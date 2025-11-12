#include<iostream>
#include<cstdio>
#include<string>
#include<cctype>
#include<algorithm>
using namespace std;

bool cmp(char a,char b){
	return a>b;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,ans;
	cin>>s;
	for(auto x:s) 
		if(isdigit(x)) ans+=x;
	sort(ans.begin(),ans.end(),cmp);
	cout<<ans;
	return 0;
}
