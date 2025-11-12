//100 YangShao_Culture
#include<bits/stdc++.h>
using namespace std;
string s;
int t[10];
void solve(){
	cin>>s;
	bool fl=1,nfl=1;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			fl=0;
			if(s[i]!='0'){
				nfl=0;
			}
			t[s[i]-'0']++;
		}
	}
	if(fl||nfl){
		cout<<0;
		return ;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=t[i];j++){
			cout<<i;
		}
	}
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	solve();
	return 0;
} 
