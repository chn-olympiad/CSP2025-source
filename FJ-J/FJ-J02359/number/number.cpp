#include<bits/stdc++.h>
using namespace std;

int str[10];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		char ch=s[i];
		if(ch>='0' && ch<='9'){
			int p=ch-'0';
			str[p]++;
		}
	}
	for(int i=9;i>=0;i--){
		int j=str[i];
		for(int k=1;k<=j;k++){
			cout<<i;
		}
	}
	return 0;
}
