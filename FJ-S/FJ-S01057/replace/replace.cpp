#include <iostream>
#include <cstring>
#include <cstdio>
#define p1 3
#define p2 2
#define m1 998244353
#define m2 1000000007
using namespace std;
int n,q,s[200005][2][2],len[200005],P1[5000005] = {1},P2[5000005] = {1},t[2][5000005][2],S,E,ans;
char c[2][5000005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for(int i = 1;i <= 500000;i++){
		P1[i] = 1ll*P1[i-1]*p1%m1;
		P2[i] = 1ll*P2[i-1]*p2%m2;
	}
	cin >> n >> q;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < 2;j++){
			cin >> c[0];
			for(int k = 0;c[0][k];k++){
				len[i]++;
				s[i][j][0] = (1ll*s[i][j][0]*p1%m1+c[0][k]-'a')%m1;
				s[i][j][1] = (1ll*s[i][j][1]*p2%m2+c[0][k]-'a')%m2;
			}
		}
		len[i] >>= 1;
	}
	while(q--){
		cin >> c[0] >> c[1];
		ans = 0;
		for(int i = 0;i < 2;i++){
			t[i][0][0] = t[i][0][1] = c[i][0]-'a';
			for(int j = 1;c[0][j];j++){
				t[i][j][0] = (1ll*t[i][j-1][0]*p1%m1+c[i][j]-'a')%m1;
				t[i][j][1] = (1ll*t[i][j-1][1]*p2%m2+c[i][j]-'a')%m2;
			}
		}
		int L = strlen(c[0]);
		if(L != strlen(c[1])){
			cout << "0\n";
			continue;
		}
		for(S = 0;c[0][S] == c[1][S];S++);
		for(E = L-1;c[0][E] == c[1][E];E--);
		for(int i = 0;i < n;i++){
			for(int j = max(E-len[i]+1,0);j <= S && j+len[i] <= L;j++){
				if(s[i][0][0] == (t[0][j+len[i]-1][0]-(j?1ll*t[0][j-1][0]*P1[len[i]]%m1:0ll)+m1)%m1 && s[i][0][1] == (t[0][j+len[i]-1][1]-(j?1ll*t[0][j-1][1]*P2[len[i]]%m2:0ll)+m2)%m2 && s[i][1][0] == (t[1][j+len[i]-1][0]-(j?1ll*t[1][j-1][0]*P1[len[i]]%m1:0ll)+m1)%m1 && s[i][1][1] == (t[1][j+len[i]-1][1]-(j?1ll*t[1][j-1][1]*P2[len[i]]%m2:0ll)+m2)%m2){
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
