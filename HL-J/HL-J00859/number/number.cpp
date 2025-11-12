#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long ji[20];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]-'0'>=0 && s[i]-'0'<=9){
			ji[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		if(ji[i]!=0){
			for(int j=1;j<=ji[i];j++){
				cout<<i;
			}
		}
	}
	return 0;
}