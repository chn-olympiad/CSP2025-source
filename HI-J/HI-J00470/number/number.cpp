#include<bits/stdc++.h>
using namespace std;
int b[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i = 0;i<=s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			b[s[i]-'0']++;
		}
	}
	string ss;
	for(int i = 9;i>=0;i--){
		if(b[i]>1){
			for(;b[i]>0;b[i]--){
				cout<<i;
			}
		}else if(b[i]==1){
			cout<<i;
		}
	}
}
