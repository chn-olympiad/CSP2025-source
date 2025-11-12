#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int num[1000005],idx;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9')num[++idx]=s[i]-'0';
	}sort(num+1,num+1+idx,greater<>());
	for(int i=1;i<=idx;i++){
		cout<<num[i];
	}
	return 0;
}
