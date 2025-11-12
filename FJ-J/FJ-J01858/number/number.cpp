#include<bits/stdc++.h>
using namespace std;
string s;
int shu[11];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i = 0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			shu[s[i]-'0']++;
		}
	}
	for(int i = 9;i>=0;i--){
		for(int j = 1;j<=shu[i];j++){
			printf("%d",i);
		}
	}
	return 0;
}

