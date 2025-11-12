#include<bits/stdc++.h>
using namespace std;
string s;
int n,mp[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;++i){
		if(s[i]>='0'&&s[i]<='9') mp[s[i]-'0']++;
	}
	for(int i=9;i>=0;--i){
		for(int j=1;j<=mp[i];++j) cout<<i;
	}
	return 0;
} 
