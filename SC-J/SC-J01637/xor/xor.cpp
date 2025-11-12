#include <iostream>
using namespace std;
int n,k,ans;
int a[500005];
bool vis[500005];

 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin >> n >> k;
	for (int i = 1;i<=n;i++){
		cin >> a[i];
	}
	
	for (int i = 1;i<=n;i++){
		for (int j = 1;j<=i;j++){
			bool flag = 0;
			for (int x = j;x<=i;x++){
				if (vis[x]){
					flag = 1;
					break;
				}
			}
			if (flag) continue;
			
			int re = a[j];
			for (int x = j+1;x<=i;x++) re ^= a[x];
			
			if (re == k){
				ans++;
				for (int x = j;x<=i;x++) vis[x] = 1;
			}
		}
	}
	cout << ans;
	return 0;
}