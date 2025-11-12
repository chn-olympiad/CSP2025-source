#include<bits/stdc++.h>

using namespace std;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	long long n,k,ans = 0;
	cin >> n >> k;
	long long a[500000000];
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
		if(a[i] == k){
			ans ++;
		}
	}
	cout << ans;
	return 0;
}
