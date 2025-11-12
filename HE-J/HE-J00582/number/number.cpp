#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	char a;
	for(int i=0;i<s.size();i++){
		for(int j=i+1;j<=s.size();j++){
			if(s[i]<s[j]){
				a=s[j];
				s[j]=s[i];
				s[i]=a;
			}
		}
	}
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			cout<<s[i];
		}
	}
	return 0;
}
