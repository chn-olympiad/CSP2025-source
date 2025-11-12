#include<bits/stdc++.h>
using namespace std;
int b[10],i,l;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0')b[s[i]-'0']++;
	}
	for(i=9;i>=0;i--){
		for(l=1;l<=b[i];l++){
			cout<<i;
		}
	}
	return 0;
} 
