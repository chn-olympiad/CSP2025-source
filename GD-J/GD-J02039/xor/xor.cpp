#include <iostream>
using namespace std;
bool vis[1000010];
int xin[1000010];
int sum[1000010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	vis[0] = 1;
	for(int i = 1;i <= n;i ++){
		cin >> xin[i];
		vis[i] = 1;
	}
	int ans = 0;
	for(int i = 1;i <= n;i ++){
		sum[i] = sum[i - 1] ^ xin[i];
		for(int j = i - 1;j >= 0;j --){
			if(vis[j]){
				if((sum[i] ^ sum[j]) == k){
					ans ++;
					vis[i - 1] = 0;
					break;
				}
			}else break;
		}
	}
	cout << ans;
	return 0;
}
