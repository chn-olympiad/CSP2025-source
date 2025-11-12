#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int n,k,ans,num[500005],vis[500005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> num[i];
		num[i] ^= num[i-1];
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n - i + 1;j++){
			int r = j + i - 1;
			int ff = 0;
			for(int pp = j;pp <= r;pp++){
				if(vis[pp] != 0){
					j = vis[pp];
					ff = 1;
					break;
				}
			}
			if(ff == 1) continue;
			if((num[r] ^ num[j-1]) == k){
				ans++;
				vis[j] = r;
				vis[r] = r; 
			}
		}
	}
	cout << ans;
	return 0;
}