#include <bits/stdc++.h>
using namespace std;
int n;
long long k,a[500005],b[500005],ans = 0,maxn = -1,minn = 20000000;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		maxn = max(a[i],maxn);
		minn = min(a[i],minn);
		b[a[i]]++;
	}
	if(n <= 2){
		ans = 0;
	}
	else if(k < minn){
		ans = 0;
	}
	else if(n <= 10){
		if(k == 0){
			if(maxn == 0){
				ans = 0;
			}
			else{
				ans = 1;
			}
		}
		else{
			for(int i = 1;i <= n;i++){
				if(a[i] == 1){
					ans++;
				}
			}
		}
	}
	else{
		if(k == 0) cout << 0;
		else if(k <= 1){
			if(k == 0){
				if(maxn == 0){
					ans = 0;
				}
				else{
					ans = 1;
				}
			}
			else{
				for(int i = 1;i <=n;i++){
					if(a[i] == 1){
						ans++;
					}
				}
			}
		}
		else{
			ans += b[k];
			for(int i = 1;i <= k;i++){
				int x = min(b[k - i],b[i]);
				ans += x;
				b[k - i] -= x;
				b[i] -= x;
			}
			for(int i= 1;i <= k;i++){
				for(int j = 1;j <= k;j++){
					if(i | j == k && b[i] != 0 && b[j] != 0){
						int x = min(b[j],b[i]);
						ans += x;
						b[i] -= x;
						b[j] -= x;
					}
				}
			} 
		}
	}
	cout << ans;
}
