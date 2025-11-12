#include<bits/stdc++.h>
using namespace std;
int cnt[12];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(char i:s){
		if('0'<=i and i<='9'){
			cnt[i-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int p=1;p<=cnt[i];p++){
			cout<<i;
		}
	}
	cout<<"\n";
	return 0;
}
