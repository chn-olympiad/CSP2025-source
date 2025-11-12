#include<bits/stdc++.h>
using namespace std;
int num[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	cin>>s;
	int len = s.length();
	for(int i=0;i<len;i++){
		if('0'<=s[i] and s[i]<='9'){
			num[s[i]-'0']++;
		}
	}

	for(int i=10;i>=0;i--){
		for(int j=0;j<num[i];j++){
			cout<<i;
		}
	}
	return 0;
}
