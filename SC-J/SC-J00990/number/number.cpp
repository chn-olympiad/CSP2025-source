#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	map<int,int> mp;
	for (int i = 0;i < s.size();i++){
		if (s[i] >= '0' && s[i] <= '9'){
			int a = s[i] - '0';
			mp[a]++;
		}
	}
	for (int i = 9;i >= 0;i--){
		for (int j = 0;j < mp[i];j++){
			cout<<i;
		}
	}
	return 0;
}