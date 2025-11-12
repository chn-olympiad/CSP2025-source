#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+5;
ll n, q;
string s[N][5], t[N][5];
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> s[i][1] >> s[i][2];
	}
	for(int i=1;i<=q;i++){
		ll ans=0;
		string t1, t2;
		cin >> t[i][1] >> t[i][2];
		for(int j=0;j<max(t[i][1].size(), t[i][2].size());j++){
			if(t[i][1][j]!=t[i][2][j]){
				t1+=t[i][1][j];
				t2+=t[i][2][j];
			}
		}
		for(int j=1;j<=n;j++){
			ll f1=1, f2=1, cnt1=0, cnt2=0;
			for(int k=0;k<s[j][1].size();k++){
				if(t1[cnt1]==s[j][1][k]){
					cnt1++;
				}else{
					cnt1=0;
				}
				if(t2[cnt2]==s[j][2][k]){
					cnt2++;
				}else{
					cnt2=0;
				}
			}
			if(cnt1==t1.size()&&cnt2==t2.size()){
				ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

