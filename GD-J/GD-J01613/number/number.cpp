#include<bits/stdc++.h>
using namespace std;
string s,s1;
long long a[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<a[i];j++){
			s1=s1+char(i+'0');
		}
	}
	while(s1[0]=='0'&&s1.size()!=1)s1.erase(0,1);
	cout<<s1;
	return 0;
}
