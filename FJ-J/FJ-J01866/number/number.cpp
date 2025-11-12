#include<bits/stdc++.h>
using namespace std;
string s;
int nub[15];
main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		int ch=s[i];
		if(ch>='0' && ch<='9') {
			nub[ch-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<nub[i];j++){
			cout<<i;
		}
	}
	return 0;
}

