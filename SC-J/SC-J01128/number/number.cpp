#include<bits/stdc++.h>
using namespace std;
string s;
string ans;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>s;
	int ls=s.size();
	for(int i=9;i>=0;--i){
		for(int j=0;j<ls;++j){
			if(s[j]==i+'0'){
				ans+=s[j];
			}
		}
	} 
	if(ans[0]=='0'){
		cout<<0;
		return 0;
	}
	cout<<ans;
	return 0;
} 
