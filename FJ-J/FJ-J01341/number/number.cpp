#include<bits/stdc++.h>
using namespace std;
string s;
int su[1010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<(int)(s.size());i++){
		char c=s[i];
		if(isdigit(c)) su[c-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(;su[i];su[i]--) cout<<i;
	}
	return 0;
}
