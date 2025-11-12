#include<bits/stdc++.h>
using namespace std;
string s;
int b[100];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(char i:s){
		if(i>='0'&&i<='9'){
			int x=i-'0';
			b[x]++;
		}
	}
	for(int i=9;i>=0;i--){
		while(b[i]--){
			cout<<i;
		}
	}
	return 0;
}
