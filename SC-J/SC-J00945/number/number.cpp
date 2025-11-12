#include<bits/stdc++.h>
using namespace std;
int mp[1000100];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<(int)s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			mp[s[i]-'0']+=1;
		}
	}
	for(int i=9;i>=0;i--){
		while(mp[i]--){
			cout<<i;
		}
	}
	return 0;
}
