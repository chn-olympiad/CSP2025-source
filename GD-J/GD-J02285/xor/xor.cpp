#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	ll sum = 0,ans = 0;
	for(int i = 1;i <= n;i++){
		if(a[i] == k){
			ans++;
			sum = 0;
			continue;
		}
		sum ^= a[i];
		if(sum == k){
			ans++;
			sum = 0;
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
