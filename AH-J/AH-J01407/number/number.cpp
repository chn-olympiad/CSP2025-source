#include<bits/stdc++.h>
using namespace std;
string s;
int t[300];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			t[s[i]]++;
		}
	}
	for(int i=57;i>=48;i--){
		if(t[i]!=0){
			for(int j=1;j<=t[i];j++){
				cout<<(char)(i);
			}
		}
	}
	return 0;
}
