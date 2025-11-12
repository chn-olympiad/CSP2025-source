#include<bits/stdc++.h>
using namespace std;
int n,k,a[500007],sum[500007];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	bool f = 1,f1 = 1;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
		if(a[i]!=1)f = 0;
		if(a[i]>1)f1 = 0;
		sum[i] = a[i]^sum[i-1];
	}if(f){
		cout << n/2;
		return 0;
	}if(f1){
		if(k==0){
			int ans = 0,m = n;
			for(int i = 1;i<=n;i++){
				if(a[i]==0){
					ans++;
					m--;
				}
			}cout << ans+m/2;
		}else{
			int ans = 0;
			for(int i = 1;i<=n;i++){
				if(a[i]==1){
					ans++;
				}
			}cout << ans;
		}return 0;
	}int ans = 0;
	for(int i = 1;i<=n;i++){
		for(int j = i;j<=n;j++){
			if((sum[j]^sum[i-1])==k){
				ans++;
				i = j+1;
			}
		}
	}cout << ans;
	return 0;
} 
