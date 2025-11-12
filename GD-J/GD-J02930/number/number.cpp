#include<bits/stdc++.h>
using namespace std;
long long d[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<=9;i++){
		d[i]=0;
	}
	for(int i=0;i<=s.length()-1;i++){
		if(s[i]>='0'&&s[i]<='9'){
			d[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<=d[i]-1;j++){
			cout<<i;
		}
	}
	return 0;
}
