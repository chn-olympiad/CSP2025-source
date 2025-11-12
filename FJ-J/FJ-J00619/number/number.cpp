#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
string s;
int num[1000005],topp;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') num[topp++]=s[i]-'0';
	}
	sort(num,num+topp,cmp);
	for(int i=0;i<topp;i++){
		cout<<num[i];
	}
	return 0;
}
