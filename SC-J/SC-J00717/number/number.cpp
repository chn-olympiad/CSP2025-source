#include <bits/stdc++.h>

using namespace std;

#define int long long

int cnt[30];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	string ans="";
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			int num=s[i]-'0';
			cnt[(int)num]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=cnt[i];j++){
			cout<<i;
		}
	}
	return 0;
}