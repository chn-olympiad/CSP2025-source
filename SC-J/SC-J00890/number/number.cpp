#include<bits/stdc++.h>
#define int long long
using namespace std;

int num[15];

signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s;cin>>s;
	for(int i=0;i<(int)s.size();i++){
		if(s[i]<='9' && s[i]>='0') num[s[i]-'0']++;
	}	
	for(int i=9;i>=0;i--){
		for(int j=1;j<=num[i];j++){
			cout<<i;
		}
	}
	return 0;
}