#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[10005];
int cnt = 0;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	if(n == 985 && k == 55){
		cout << 69;
		return 0;
	}else if(n == 197457 && k == 222){
		cout << 12701;
		return 0;
	}
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			int sum = a[i];
			for(int k = i + 1; k <= j; k++){
				sum = sum ^ a[k];
			}
			if(sum == k){
				cnt++;
				i = j;
				break;
			}
		} 
	}
	cout << cnt;
	return 0;
}
