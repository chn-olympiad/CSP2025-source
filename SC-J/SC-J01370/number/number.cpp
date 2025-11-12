#include<bits/stdc++.h>
using namespace std;
int l[10];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]-'0'<=9&&s[i]-'0'>=0){
			l[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		if(l[i]!=0){
			for(int j=1;j<=l[i];j++){
				cout<<i;
			}
		}
	}
	return 0;
}