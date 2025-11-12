#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int t[10];
	string s;
	int ch;
	cin>>s;
	while(cin>>ch){
		if('0'<=ch&&ch<='9'){
			t[ch-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=t[i];j++){
			cout<<i;
		}
	}
	return 0;
}
