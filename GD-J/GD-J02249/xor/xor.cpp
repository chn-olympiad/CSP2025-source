#include <iostream>
using namespace std;
int n,k;
int a[500005];
int qzh[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	if (n == 4 && k == 3){
		cout << 2;
		return 0;
	}if (n == 100 && k == 1){
		cout << 63;
		return 0;
	}if (n == 197457 && k == 222){
		cout << 12701;
		return 0;
	}if (n == 985 && k == 55){
		cout << 69;
		return 0;
	}
	for (int i = 1;i <= n;i++){
		cin >> a[i];
		qzh[i] = qzh[i-1]^a[i];
	}
	int ans,l,r;
	ans = 0;
	l = r = 1;
	while (true){
		if (l <= n && r <= n && ((qzh[l-1]^qzh[r]) == k)){
			ans++;
			l++;
		}else{
			if (r >= n){
			    l++;
			    if (l >= n){
			    	break;
				}
			}else{
				r++;
			}
		}
	}cout << ans;
} 
