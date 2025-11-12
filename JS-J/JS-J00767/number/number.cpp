#include<bits/stdc++.h>
using namespace std;
string s;
long long num[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(char i:s){
		if(i>='0'&&i<='9'){
			num[i-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=num[i];j++){
			cout<<i;
		}
	}
	return 0;
}
