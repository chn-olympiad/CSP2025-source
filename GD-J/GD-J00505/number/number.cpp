#include<bits/stdc++.h>
using namespace std;
bool is(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s="";
	cin>>s;
	int a[100005]={};
	long long zhizhen=0;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9')a[zhizhen++]=s[i]-'0';
	}
	sort(a+0,a+zhizhen,is);
	for(int i=0;i<zhizhen;i++){
		cout<<a[i];
	}
	return 0;
}
