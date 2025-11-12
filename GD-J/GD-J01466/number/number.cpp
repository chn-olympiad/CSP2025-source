#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	int cnt[10]={0};
	string s;
	cin >> s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i] && '9'>=s[i]){
			cnt[s[i]-'0']++;
		}
	}
	string ans="";
	for(int i=9;i>=0;i--){
		for(int j=1;j<=cnt[i];j++){
			ans+=('0'+i);
		}
	}
	cout << ans;
	
	return 0;
 } 
