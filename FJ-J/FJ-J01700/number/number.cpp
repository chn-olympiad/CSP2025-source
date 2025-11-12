#include<bits/stdc++.h>
#include<string>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int num[500000],i,n=0;
	string s;
	cin>>s;
	for(i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') num[n++]=s[i]-'0';
	}
	sort(num,num+n);
	for(i=n-1;i>=0;i--){
		cout<<num[i];
	}
	return 0;
}
