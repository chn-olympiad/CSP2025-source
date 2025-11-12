#include<bits/stdc++.h>
using namespace std;
int aa[11];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			aa[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int l=1;l<=aa[i];l++){
			printf("%d",i);
		}
	}
	return 0;
}
