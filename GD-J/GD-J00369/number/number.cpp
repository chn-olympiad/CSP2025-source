#include<bits/stdc++.h>
using namespace std;
string s;
int t[10];
int maxl;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			t[s[i]-'0']++;
			maxl=max(maxl,s[i]-'0');
		}
	}
	for(int i=maxl;i>=0;i--){
		for(int j=0;j<t[i];j++){
			cout<<i;
		}
	}
	return 0;
}

