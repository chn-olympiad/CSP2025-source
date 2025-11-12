#include <bits/stdc++.h>
using namespace std;
string s,ans;
int wl[100];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			wl[s[i]-'0']++;
		}
	} 
	for(int i=9;i>=0;i--){
		char c=i+'0';
		for(int j=1;j<=wl[i];j++){
			ans=ans+c;
		}
	}
	cout<<ans;
	return 0;
} 
