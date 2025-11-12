#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
int ans[20];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			ans[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=ans[i];j++){
			cout<<i;
		}
	}
	return 0;
} 
