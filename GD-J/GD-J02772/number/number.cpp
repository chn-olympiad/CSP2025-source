#include<bits/stdc++.h>
using namespace std; 
string s;
int b[11],op;
int main(){
  	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')b[s[i]-'0']++;
	}
	for(int i=9;i>=1;i--){
		if(b[i]){
			op=1;
			for(int j=0;j<b[i];j++)cout<<i;
		}
	}
	if(!op)cout<<0;
	else for(int i=0;i<b[0];i++)cout<<0;
	return 0;
}
