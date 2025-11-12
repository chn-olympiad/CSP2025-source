#include <bits/stdc++.h>
using namespace std;
map<char,int> mp;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]<='9'&&s[i]>='0'){
			mp[s[i]]++;
		}
	}
	if(mp['9']!=0) for(int i=1;i<=mp['9'];i++) cout<<9;
	if(mp['8']!=0) for(int i=1;i<=mp['8'];i++) cout<<8;
	if(mp['7']!=0) for(int i=1;i<=mp['7'];i++) cout<<7;
	if(mp['6']!=0) for(int i=1;i<=mp['6'];i++) cout<<6;
	if(mp['5']!=0) for(int i=1;i<=mp['5'];i++) cout<<5;
	if(mp['4']!=0) for(int i=1;i<=mp['4'];i++) cout<<4;
	if(mp['3']!=0) for(int i=1;i<=mp['3'];i++) cout<<3;
	if(mp['2']!=0) for(int i=1;i<=mp['2'];i++) cout<<2;
	if(mp['1']!=0) for(int i=1;i<=mp['1'];i++) cout<<1;
	if(mp['0']!=0) for(int i=1;i<=mp['0'];i++) cout<<0;
	return 0;
}
