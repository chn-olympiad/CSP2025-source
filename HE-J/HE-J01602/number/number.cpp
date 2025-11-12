#include<bits/stdc++.h>
using namespace std;
string s_chen;
int a_chen[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s_chen;
	for(int i=0;i<s_chen.size();i++){
		if(s_chen[i]>='0'&&s_chen[i]<='9'){
			a_chen[s_chen[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		if(a_chen[i]==0){
			continue;
		}else{
			for(int j=1;j<=a_chen[i];j++){
				cout<<i;
			}
		}
	}
	return 0;
}
