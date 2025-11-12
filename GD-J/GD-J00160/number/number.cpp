#include<bits/stdc++.h>
using namespace std;
string s;
int n,cnt[15],fl;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;n=s.size();s=' '+s;
	for(int i=1;i<=n;i++){
		if('0'<=s[i]&&s[i]<='9') cnt[s[i]-'0']++;
	}
	for(int i=9;i>=1;i--){
		while(cnt[i]--){fl=1;cout<<i;}
	}
	if(!fl) cout<<0;
	else while(cnt[0]--) cout<<0;
	return 0;
}
