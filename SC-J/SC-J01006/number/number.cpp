#include<bits/stdc++.h>
using namespace std;
string s;
unordered_map<int,int>mp;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		mp[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=mp[i];j++)cout<<i;
	}
	return 0;
}