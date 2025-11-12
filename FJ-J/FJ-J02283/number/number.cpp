#include<bits/stdc++.h>
using namespace std;

string str;
int num[10];

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	cin>>str;
	for(int i=0;i<str.length();i++){
		char s = str[i];
		if(s>='0'&&s<='9'){
			++num[(int)(s-'0')];
		}
	}
	for(int i=9;i>=0;i--){
		while(num[i]){
			cout<<i;
			--num[i];
		}
	}
	return 0;
}
