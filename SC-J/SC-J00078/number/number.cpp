#include<bits/stdc++.h>
using namespace std;
string s;
int cnt,ton[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			ton[int(s[i]-'0')]++;
		}
	}
	for(int i=10;i>=0;i--){
		if(ton[i]!=0){
			while(ton[i]--){
				cout<<i;
			}
		}
	}
	return 0;
}