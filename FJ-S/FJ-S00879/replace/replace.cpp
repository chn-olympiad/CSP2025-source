#include<bits/stdc++.h>
using namespace std;
int n,q,cnt;
string s1,s2;
int b[5000005],dp[5000005];
int q(){
	
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> s1 >> s2;
		int cnt1 = 0,cnt2 = 0;
		while(s1[++cnt1] != s1[cnt1 - 1]) cnt1++;
		while(s2[++cnt2] != s2[cnt2 - 1]) cnt2++;
		b[++cnt] = cnt2 - cnt1;
	}
	sort(b + 1, b + 1 + cnt);
	while(q--){
		cin >> s1 >> s2;
		cnt1 = cnt2 = 0;
		memset(dp,0x3f,sizeof dp);
		while(s1[++cnt1] != s1[cnt1 - 1]) cnt1++;
		while(s2[++cnt2] != s2[cnt2 - 1]) cnt2++;
		int res = cnt2 - cnt1;
		while(1){
			int k = q();
			if(k != -1){
				cout << k <<endl;
				break;
			}
			k = q1();
			if(k != -1){
				cout << k <<endl;
				break;
			}
		}
	}
	return 0;
} 
