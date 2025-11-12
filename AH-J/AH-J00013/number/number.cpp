#include<bits/stdc++.h>
using namespace std;
int len;
string s;
string ans;
map<char,int> mp;
map<char,int>::iterator it;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> s;
	len=s.length();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			mp[s[i]]++;
		}
	}
	for(it=mp.begin();it!=mp.end();it++){
		for(int i=1;i<=it->second;i++){
			ans=it->first+ans;
		}
	}
	cout << ans;
	return 0;
}
