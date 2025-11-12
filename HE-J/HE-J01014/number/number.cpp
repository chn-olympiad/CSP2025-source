#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a[1003]={0},ma=-1,b[1004];
	int sum=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0'){
		    a[i]=s[i]-'0';
			ma=max(ma,a[i]);
			b[i]=ma;
			//cout<<ma;
			ma=0;
			cout<<b[i];

		}
	}
	return 0;
}
