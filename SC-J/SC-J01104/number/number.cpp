#include<bits/stdc++.h>
#define int long long
using namespace std;
char x;
int mp[1145],kk;
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i])){
			mp[s[i]]++;
			if(s[i]!='0')kk=1;
		}
	}	
	string ans;
	for(int i='9';i>='0';i--){
		while(mp[i]--)ans=ans+char(i);
	}
	if(kk)cout<<ans;
	else cout<<'0';
	return 0;
}
