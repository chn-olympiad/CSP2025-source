#include<bits/stdc++.h>
using namespace std;
string s;
int t[11];
string ans;
string read(){
	string rt;
	char c=getchar();
	while((c>='a'&&c<='z')||(c>='0'&&c<='9')){
		rt+=c;
		c=getchar();
	}
	return rt;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	s=read();
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			t[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=t[i];j++){
			ans+=i+'0';
		}
	}
	cout<<ans;
	return 0;
}