#include<bits/stdc++.h>
using namespace std;
int nums[10];
string s;
int main(){

	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	for(int i=0;i<s.length();i++){
		if(s[i]>='0' and s[i]<='9'){
			nums[int(s[i]-'0')]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<nums[i];j++){
			printf("%d",i);
		}
	}

	return 0;
}

