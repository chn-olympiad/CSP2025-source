#include<bits/stdc++.h>
using namespace std;
//RP++
string s;
int num[1145141],idx;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[idx++]=s[i]-'0';
		}
	}
	sort(num,num+idx,cmp);
	for(int i=0;i<idx;i++){
		cout<<num[i];
	}
	return 0;
}
