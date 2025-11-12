#include <bits/stdc++.h>
using namespace std;
int sz[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		char m=s[i];
		if(m>='0'&&m<='9'){
			sz[m-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(sz[i]--){
			cout<<i;
		}
	}
	return 0;
}
