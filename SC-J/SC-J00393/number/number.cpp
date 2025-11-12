#include<bits/stdc++.h>
using namespace std;
string s;
int num[1000005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int t=1;
	for(int i=0;i<s.size();i++){
		if(s[i]-'0'>=0 and s[i]-'0'<=9)
			num[t++]=s[i]-'0';
	}
	sort(num+1,num+1+t,cmp);
	for(int i=1;i<t;i++){
		cout<<num[i];
	}
	return 0;
}