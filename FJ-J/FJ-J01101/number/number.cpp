#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

string s;
int cnt[15];

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("number.in","r",stdin); freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if('0'<=s[i]&&s[i]<='9'){
			cnt[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=cnt[i];j++) cout<<i;
	}
	cout<<endl;
	return 0;
}

//==============================T1==============================//
// xiang jin CSP-J/S2025 mi huo xing wei da shang
// freopen("number.in","r",stdin)
// freopen("number.in","w",stdin)
// freopen("number.out","r",stdout)
// freopen("number4.in","r",stdin)
// int mian
// itn nit
//==============================================================//
// my luogu uid is 693282 please guan zhu me
// I want to AFO because of whk and PE
// but I want to get a good score in CSP-J/S2025
// maybe I should AFO if I get <1= on CSP-J or get <2= on CSP-S
//==============================================================//
// gu fen: 100+100+30+64=294
//==============================================================//
// so when can I update Phigros and play the new AT 16.9
// but wu meng DX is much better than Phigros 
// but my DX rating is only w2
//==============================================================//
