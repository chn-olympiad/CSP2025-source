#include <bits/stdc++.h>
using namespace std;
long long a[1005],n,k,ans;
long long b[1005][1005],c[1005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(long long i = 1;i <= n;i++) cin >> a[i];
	for(long long i = 2;i <= n;i++) a[i] = a[i] ^ a[i-1];
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++) b[i][j] = -1;
	} 
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			b[i][j] = a[i-1] ^ a[j];
		}
	}
	//for(int i = 1;i <= n;i++){
	//	for(int j = 1;j <= n;j++) cout << b[i][j] << " ";
	//}  
	//cout << endl;
	for(int i = 0;i < n;i++){
		for(int j = 1;j <= n-i;j++){
			int y = 0;
			for(int x = j;x <= j+i;x++){
				if(c[x] == 1){
					y = 1;
					break;
				}
			}
			if(b[j][i+j] == k && y == 0){
				ans++;
				c[j]++;
				c[j + i+1]--;
				for(int x = j+1;x <= i+j+1;x++){
					c[x] = c[x-1] + c[x];
				}
			}
		}
	}
	cout << ans;
	return 0;
}
