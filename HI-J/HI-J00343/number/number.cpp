#include<bits/stdc++.h>
using namespace std;
string s;
char a=0;
int u=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&'9'>=s[i]){
			a=s[i];
			u=i;
			break;
		}
	}
	for(int i=0;i<s.size();i++){
		if((s[i]>='0'&&'9'>=s[i])&&(s[i]>a)){
			swap(s[i],s[u]);
			a=s[i];
			u=i;
		}
	}
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&'9'>=s[i]){
			cout<<s[i];
		}
	}
	return 0;
}

