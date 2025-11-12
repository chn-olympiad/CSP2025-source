#include<bits/stdc++.h>
using namespace std;
long long n, k;
const long long N = 1e5 + 10;
long long a[N];
long long vis[N];
long long check(long long u, long long x){
	long long ans = a[u + 1] ^ a[u];
	for(long long i = u + 2; i <= x; i++)ans ^= a[i];
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(long long i = 1 ; i <= n ; i++)cin >> a[i];
	long long ans = 0;
	for(long long i = 1 ; i <= n ; i++){
		for(long long j = i; j <= n ; j++){
			if(i == j && a[i] == k){
				ans++;
				continue;
			}
			if(i == j && a[i] != k)continue;
			if(check(i,j) == k){
				ans++;
				i = j + 1;
			}
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

