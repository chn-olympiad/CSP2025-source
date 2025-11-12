#include<bits/stdc++.h>
using namespace std;
string s;
map<int,int,greater<int> >mp;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i])) mp[s[i]-'0']++;
	}
	for(auto x:mp){
		for(int i=1;i<=x.second;i++){
			cout<<x.first;
		}
	}
	return 0;
}
/*
number

×Ô²â:
2sdf1d345gs6gfd7aw8 

d0

Ô¸´ËÐÐ,ÖÕµÖÈºÐÇ ÈªÃÅÓÀ´æ 
icebird_ldyy code
*/
